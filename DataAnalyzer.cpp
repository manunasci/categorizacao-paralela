#include "DataAnalyzer.hpp"

namespace CategorizacaoParalela {
    float DataAnalyzer::mean(const std::vector<float> vector) {
        int size = vector.size();
        
        float sum = 0.0, mean = 0.0;

        for (int i = 0; i < size; ++i) {
            sum += vector[i];
        }

        mean = sum / size;

        return mean;
    }

    float DataAnalyzer::median(const std::vector<float> vector) {
        if (vector.empty()) {
            return 0.0f;
        }

        const std::size_t n = vector.size();
        const std::size_t mid = n / 2;

        if (n % 2 != 0) {
            return vector[mid];
        }

        return (vector[mid - 1] + vector[mid]) * 0.5f;
    }

    float DataAnalyzer::variance(const std::vector<float> vector) {
        float variance = 0.0;
        int vector_size = vector.size();

        if (vector.empty()) {
            return variance;
        }

        float median = DataAnalyzer::median(vector);

        float sum_sqs = 0.0f;

        for (int i = 0; i < vector_size; ++i) {
            float dif = vector[i] - median;

            sum_sqs += dif * dif;
        }

        variance = sum_sqs / vector_size;

        return variance;
    }

    float DataAnalyzer::std_deviation(const std::vector<float> vector) {
        return 0.0;
    }

    float DataAnalyzer::iqr(const std::vector<float> vector) {
        return 0.0;
    }

}
