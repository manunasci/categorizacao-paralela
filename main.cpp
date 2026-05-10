#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

    bool hasParametros = (argc > 1);
    std::string dataset = "dataset_00_1000_sem_virg.csv";

    if (hasParametros) {
        dataset = argv[1];
    }

    std::string dataset_full_path = "./" + dataset;

    std::cout << dataset_full_path << std::endl;

    return 0;
}
