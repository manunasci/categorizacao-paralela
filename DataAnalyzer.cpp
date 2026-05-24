#include "DataAnalyzer.hpp"

namespace CategorizacaoParalela {
    float DataAnalyzer::mean(const std::vector<float>& vector) {
        int size = (int)vector.size();
        
        float sum = 0.0f, mean = 0.0f;

        for (int i = 0; i < size; ++i) {
            sum += vector[i];
        }

        mean = sum / (float)size;

        return mean;
    }

    float DataAnalyzer::median(const std::vector<float>& vector) {
        if (vector.empty()) {
            return 0.0f;
        }

        const int size = (int)vector.size();
        const int mid = size / 2;

        if (size % 2 != 0) {
            return vector[mid];
        }

        return (vector[mid - 1] + vector[mid]) * 0.5f;
    }

    float DataAnalyzer::variance(const std::vector<float>& vector) {
        float variance = 0.0f;
        int vector_size = (int)vector.size();

        if (vector.empty()) {
            return variance;
        }

        float median = DataAnalyzer::median(vector);

        float sum_sqs = 0.0f;

        for (int i = 0; i < vector_size; ++i) {
            float dif = vector[i] - median;

            sum_sqs += dif * dif;
        }

        variance = sum_sqs / (float)vector_size;

        return variance;
    }

    float DataAnalyzer::std_deviation(const std::vector<float>& vector) {
        return 0.0f;
    }

    float DataAnalyzer::iqr(const std::vector<float>& vector) {
        return 0.0f;
    }

}
