#ifndef CATEGORIZACAOPARALELA_DATAHANDLER_HPP
#define CATEGORIZACAOPARALELA_DATAHANDLER_HPP

#include <vector>

namespace CategorizacaoParalela {
    class DataHandler {
    public:
        void merge_blocks(float* vector, int left, int mid, int right);

        void execute_merge_sort(float* vector, int left, int right);

        void sort(std::vector<float>& vector);
    };
}

#endif //CATEGORIZACAOPARALELA_DATAHANDLER_HPP
