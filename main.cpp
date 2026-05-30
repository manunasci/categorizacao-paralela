#include <iostream>
#include <string>

#include <fstream>
#include <sstream>

#include "DataValidator.h"
#include "DataAnalyzer.hpp"
#include "FileData.hpp"

void convert_file_data_to_tables(std::ifstream& dataset_file, CategorizacaoParalela::FileData& file_data) {
    std::string linhaTexto;
    std::string celula;

    if (std::getline(dataset_file, linhaTexto)) {
        std::stringstream ss(linhaTexto);

        while (std::getline(ss, celula, ',')) {
            CategorizacaoParalela::ColumnTables table;
            table.table_name = "td_" + celula;
            file_data.columns.push_back(table);
        }
    }

    std::size_t line_i = 1;

    while (std::getline(dataset_file, linhaTexto)) {
        std::stringstream ss(linhaTexto);
        std::size_t ix_col = 0;

        while (std::getline(ss, celula, ',')) {
            if (ix_col < file_data.columns.size()) {
                if ((int)line_i == 1) {
                    file_data.columns[ix_col].is_num = CategorizacaoParalela::DataValidator::is_num(celula);
                }
                file_data.columns[ix_col].row_ids.push_back(line_i);
                file_data.columns[ix_col].values.push_back(celula);
            }
            ++ix_col;
        }
        ++line_i;
    }
}

CategorizacaoParalela::FileData save_file_data(const std::string& file_path) {
    CategorizacaoParalela::FileData file_data;
    std::ifstream dataset_file(file_path);

    if (!dataset_file.is_open()) {
        throw std::runtime_error("Erro: O arquivo não foi encontrado!");
    }

    std::string lookaheadLine;

    if (std::getline(dataset_file, lookaheadLine)) {
        if (!std::getline(dataset_file, lookaheadLine)) {
            throw std::runtime_error("Erro: O arquivo contém apenas o cabeçalho e nenhuma linha de dados!");
        }
    } else {
        throw std::runtime_error("Erro: O arquivo está completamente vazio!");
    }

    dataset_file.clear();
    dataset_file.seekg(0, std::ios::beg);

    convert_file_data_to_tables(dataset_file, file_data);

    dataset_file.close();

    return file_data;
}

void run_descriptive_statistic(CategorizacaoParalela::FileData &file_data) {
    for (std::size_t k = 0; k < file_data.columns.size(); ++k) {
        if (file_data.columns[k].is_num) {
            std::vector<float> dadosNumericos;
            dadosNumericos.reserve(file_data.columns[k].values.size());

            for (const std::string& valorTexto : file_data.columns[k].values) {
                try {
                    dadosNumericos.push_back(std::stof(valorTexto));
                } catch (const std::exception& e) {
                    dadosNumericos.push_back(0.0f);
                }
            }

            if (!dadosNumericos.empty()) {
                std::cout << "\n=== Estati'sticas do dicionário: " << file_data.columns[k].table_name << " ===\n";
                std::cout << "Me'dia: "              << CategorizacaoParalela::DataAnalyzer::mean(dadosNumericos) << "\n";
                std::cout << "Mediana: "            << CategorizacaoParalela::DataAnalyzer::median(dadosNumericos) << "\n";
                std::cout << "Variancia: "          << CategorizacaoParalela::DataAnalyzer::variance(dadosNumericos) << "\n";
                std::cout << "Desvio Padrao: "      << CategorizacaoParalela::DataAnalyzer::std_deviation(dadosNumericos) << "\n";
                std::cout << "IQR (Interquartil): " << CategorizacaoParalela::DataAnalyzer::iqr(dadosNumericos) << "\n";
            }

        } else {
            std::cout << "Ana'lise quant. " << file_data.columns[k].table_name << "] pulada (nao e' nume'rica)." << std::endl;
        }

        std::vector<std::string> modas = CategorizacaoParalela::DataAnalyzer::mode(file_data.columns[k].values);

        std::cout << "Moda(s): ";
        for (std::size_t i = 0; i < modas.size(); ++i) {
            std::cout << modas[i] << (i + 1 < modas.size() ? ", " : "");
        }
        std::cout << "\n";
    }
}

void exibir_amostragem_dados(const CategorizacaoParalela::FileData& file_data) {
    char verDados;
    std::cout << "\nGostaria de ver os dados amostrados das tabelas? (S/N): ";
    std::cin >> verDados;

    if (verDados != 'S' && verDados != 's') {
        return;
    }

    for (std::size_t k = 0; k < file_data.columns.size(); ++k) {
        const auto& coluna = file_data.columns[k];
        std::size_t totalLinhas = coluna.values.size();

        std::cout << "\n=============================================\n";
        std::cout << "Exibindo amostragem para: " << coluna.table_name << "\n";
        std::cout << "=============================================\n";

        std::size_t limiteHead = std::min(totalLinhas, static_cast<std::size_t>(15));
        for (std::size_t i = 0; i < limiteHead; ++i) {
            std::cout << "[" << coluna.table_name << "] "
                      << "ID: " << coluna.row_ids[i] << " | "
                      << "Valor: " << coluna.values[i] << "\n";
        }

        if (totalLinhas > 30) {
            std::cout << "...\n... [ " << (totalLinhas - 30) << " linhas ocultadas para amostragem ] ...\n...\n";
        }

        if (totalLinhas > 15) {
            std::size_t inicioTail = (totalLinhas > 30) ? (totalLinhas - 15) : 15;
            for (std::size_t i = inicioTail; i < totalLinhas; ++i) {
                std::cout << "[" << coluna.table_name << "] "
                          << "ID: " << coluna.row_ids[i] << " | "
                          << "Valor: " << coluna.values[i] << "\n";
            }
        }

        if (k + 1 < file_data.columns.size()) {
            char proximaTabela;
            std::cout << "\nGostaria de ir para a proxima tabela/dicionario? (S/N): ";
            std::cin >> proximaTabela;

            if (proximaTabela == 'N' || proximaTabela == 'n') {
                std::cout << "Encerrando exibicao a pedido do usuario.\n";
                break;
            }
        } else {
            std::cout << "\nFim do conjunto de dados atingido.\n";
        }
    }
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

    run_descriptive_statistic(file_data);

    exibir_amostragem_dados(file_data);

    return 0;
}
