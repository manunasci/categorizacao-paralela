#ifndef CATEGORIZACAOPARALELA_DATAANALYZER_HPP
#define CATEGORIZACAOPARALELA_DATAANALYZER_HPP

#include <vector>
#include <string>

namespace CategorizacaoParalela {
    class DataAnalyzer {
    public:
        static float mean(const std::vector<float>& vector);

        static std::vector<std::string> mode(const std::vector<std::string>& data);

        static float median(const std::vector<float>& vector);

        static float variance(const std::vector<float>& vector);

        static float std_deviation(const std::vector<float>& vector);

        static float iqr(const std::vector<float>& vector);
    };
}

#endif //CATEGORIZACAOPARALELA_DATAANALYZER_HPP
