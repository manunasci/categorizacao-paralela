#include "DataHandler.hpp"

#include <vector>

namespace CategorizacaoParalela {
    void DataHandler::merge_blocks(float* vector, int left, int mid, int right) {
        int left_size = mid - left + 1;
        int right_size = right - mid;

        std::vector<float> left_memory(left_size);
        std::vector<float> right_memory(right_size);

        for (int i = 0; i < left_size; i++) {
            left_memory[i] = vector[left + i];
        }
        for (int j = 0; j < right_size; j++) {
            right_memory[j] = vector[mid + 1 + j];
        }

        int left_index = 0;
        int right_index = 0;
        int result_index = left;

        while (left_index < left_size && right_index < right_size) {
            if (left_memory[left_index] <= right_memory[right_index]) {
                vector[result_index] = left_memory[left_index];
                left_index++;
            } else {
                vector[result_index] = right_memory[right_index];
                right_index++;
            }
            result_index++;
        }

        while (left_index < left_size) {
            vector[result_index] = left_memory[left_index];
            left_index++;
            result_index++;
        }

        while (right_index < right_size) {
            vector[result_index] = right_memory[right_index];
            right_index++;
            result_index++;
        }
    }

    void DataHandler::execute_merge_sort(float* vector, int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        #pragma omp task shared(array)
        execute_merge_sort(vector, left, mid);

        #pragma omp task shared(array)
        execute_merge_sort(vector, mid + 1, right);

        #pragma omp taskwait
        merge_blocks(vector, left, mid, right);
    }

    void DataHandler::sort(std::vector<float>& vector) {
        int vector_size = (int)vector.size();

        if (vector_size <= 1) {
            return;
        }

        #pragma omp parallel num_threads(4) if(vector_size >= 10000)
        {
            #pragma omp single nowait
            {
                execute_merge_sort(vector.data(), 0, vector_size - 1);
            }
        }
    }
}
