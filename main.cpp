#include <iostream>
#include <string>

#include <fstream>
#include <sstream>
#include <vector>

#include "DataValidator.h"
#include "FileData.hpp"

CategorizacaoParalela::FileData save_file_data(const std::string& file_path) {
    CategorizacaoParalela::FileData file_data;
    std::ifstream dataset_file(file_path);

    if (!dataset_file.is_open()) {
        throw std::runtime_error("Erro: O arquivo não foi encontrado!");
    }

    std::vector<std::vector<std::string>> matriz;

    std::string linhaTexto;

    while (std::getline(dataset_file, linhaTexto)) {
        std::stringstream ss(linhaTexto);
        std::string celula;

        std::vector<std::string> linhaDaMatriz;

        while (std::getline(ss, celula, ',')) {
            linhaDaMatriz.push_back(celula);
        }

        matriz.push_back(linhaDaMatriz);
    }

    dataset_file.close();

    int n_cols_file = matriz[0].size();

    if (matriz.size() < 2) {
        throw std::runtime_error("Erro: O arquivo deve conter pelo menos o cabeçalho e uma linha de dados.");
    }

    for (int j = 0; j < n_cols_file; ++j) {
        CategorizacaoParalela::Column col;
        col.col_name = matriz[0][j];

        col.ix = j;
        col.is_num = CategorizacaoParalela::DataValidator::is_num(matriz[1][j]);

        file_data.columns.push_back(col);
    }

    return file_data;
}

int main(int argc, char* argv[]) {
    bool hasParametros = (argc > 1);
    std::string dataset_file_name = "dataset_00_1000_sem_virg.csv";

    if (hasParametros) {
        dataset_file_name = argv[1];
    }

    std::string dataset_full_path = "../" + dataset_file_name;

    std::cout << dataset_full_path << std::endl;

    CategorizacaoParalela::FileData file_data = save_file_data(dataset_full_path);

    return 0;
}
