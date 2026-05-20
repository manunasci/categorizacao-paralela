#include "DataValidator.h"

namespace CategorizacaoParalela {
    bool DataValidator::is_num(const std::string& s) {
        if (s.empty()) return false;
        size_t tam_string = s.length();

        int pontos = 0;
        int inicio = 0;

        if (s[0] == '-') {
            if (tam_string == 1) return false;
            inicio = 1;
        }

        for (int i = inicio; i < tam_string; i++) {
            if (s[i] == '.') {
                pontos++;
                if (pontos > 1) return false;
            }
            else if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }

        if (s == ".") return false;

        return true;
    }
}