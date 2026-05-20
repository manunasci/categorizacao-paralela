#ifndef CATEGORIZACAOPARALELA_FILEDATA_HPP
#define CATEGORIZACAOPARALELA_FILEDATA_HPP

#include <vector>
#include <string>

struct Column {
    std::string col_name;
    int is_num = 0;
};

struct FileData {
    std::vector<Column> columns;
};

#endif //CATEGORIZACAOPARALELA_FILEDATA_HPP
