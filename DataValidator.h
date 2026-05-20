#ifndef CATEGORIZACAOPARALELA_DATAVALIDATOR_H
#define CATEGORIZACAOPARALELA_DATAVALIDATOR_H

#include <string>

namespace CategorizacaoParalela {

    class DataValidator {
    public:
        static bool is_num(const std::string& s);
    };

}

#endif //CATEGORIZACAOPARALELA_DATAVALIDATOR_H
