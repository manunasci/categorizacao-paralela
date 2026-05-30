#ifndef CATEGORIZACAOPARALELA_FILEDATA_HPP
#define CATEGORIZACAOPARALELA_FILEDATA_HPP

#include <vector>
#include <string>

namespace CategorizacaoParalela {
    struct ColumnTables {
        bool is_num = false;
        std::string table_name;
        std::vector<std::size_t> row_ids;
        std::vector<std::string> values;
    };

    struct FileData {
        std::vector<ColumnTables> columns;
    };
}

#endif
