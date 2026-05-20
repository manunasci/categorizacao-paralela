#ifndef CATEGORIZACAOPARALELA_DATAANALYZER_HPP
#define CATEGORIZACAOPARALELA_DATAANALYZER_HPP

#include <vector>

namespace CategorizacaoParalela {
    class DataAnalyzer {
    public:
        static float mean(const std::vector<float>);

        static float median(const std::vector<float>);

        static float variance(const std::vector<float>);

        static float std_deviation(const std::vector<float>);

        static float iqr(const std::vector<float>);
    };
}

#endif //CATEGORIZACAOPARALELA_DATAANALYZER_HPP
