#include <iostream>
#include <string>

#include <fstream>
#include <sstream>
#include <vector>

int main(int argc, char* argv[]) {

    bool hasParametros = (argc > 1);
    std::string dataset_file_name = "dataset_00_1000_sem_virg.csv";

    if (hasParametros) {
        dataset_file_name = argv[1];
    }

    std::string dataset_full_path = "./" + dataset_file_name;

    std::cout << dataset_full_path << std::endl;

    std::ifstream dataset_file(dataset_full_path);

    if (!dataset_file.is_open()) {
        std::cerr << "Erro: O arquivo não foi encontrado!" << std::endl;
        return 1;
    }

    std::vector<std::vector<std::string>> matriz;

    std::string linhaTexto;
    int contadorLinhas = 0;

    while (std::getline(dataset_file, linhaTexto) && contadorLinhas < 4) {
        std::stringstream ss(linhaTexto);
        std::string celula;

        std::vector<std::string> linhaDaMatriz;

        while (std::getline(ss, celula, ',')) {
            linhaDaMatriz.push_back(celula);
        }

        matriz.push_back(linhaDaMatriz);
        contadorLinhas++;
    }

    dataset_file.close();

    return 0;
}
