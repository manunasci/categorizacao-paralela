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
        return 0.0;
    }

    float DataAnalyzer::variance(const std::vector<float> vector) {
        return 0.0;
    }

    float DataAnalyzer::std_deviation(const std::vector<float> vector) {
        return 0.0;
    }

    float DataAnalyzer::iqr(const std::vector<float> vector) {
        return 0.0;
    }

}
