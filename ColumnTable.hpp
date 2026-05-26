#ifndef CATEGORIZACAOPARALELA_COLUMNTABLE_HPP
#define CATEGORIZACAOPARALELA_COLUMNTABLE_HPP

#include <string>
#include <vector>

namespace CategorizacaoParalela {
    /**
     * @brief Represents a tabular column containing row IDs and their corresponding string values.
     */
    struct ColumnTable {
        std::string table_name;
        std::vector<std::size_t> row_ids;
        std::vector<std::string> values;
    };
}

#endif
