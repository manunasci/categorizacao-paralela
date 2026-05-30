# Categorização Paralela - Analisador de Dados em C++

Este repositório contém uma aplicação em C++ voltada para a análise estatística descritiva e processamento eficiente de arquivos em formato CSV. O programa lê dados tabulares e realiza cálculos fundamentais para a análise de informações, apresentando a opção de exibir amostras dos dados processados diretamente no terminal.

O objetivo principal é oferecer uma ferramenta rápida e independente para que profissionais ou estudantes possam extrair indicadores centrais de uma base de dados (como médias e modas) sem depender de softwares pesados de análise, aproveitando o poder de processamento nativo do C++.

---

## Visão Geral do Projeto (Para Pessoas Não Técnicas)

Se o interesse for compreender a finalidade da ferramenta sem a necessidade de executar o código, esta seção apresenta um resumo do funcionamento.

O sistema atua da seguinte forma:

1.  **Leitura do Arquivo (Dataset):** O programa recebe um arquivo de texto no formato CSV (Valores Separados por Vírgula), que funciona como uma planilha. Ele identifica automaticamente o que é o cabeçalho e estrutura os dados por colunas.
2.  **Identificação de Tipos de Dados:** O sistema varre as colunas e descobre sozinho se o conteúdo de uma coluna é puramente numérico ou se contém texto/palavras.
3.  **Análise Estatística:**
    *   **Para colunas numéricas:** O programa calcula e exibe automaticamente indicadores estatísticos vitais: Média, Mediana, Variância, Desvio Padrão e o Intervalo Interquartil (IQR).
    *   **Para todas as colunas:** O programa identifica e exibe a "Moda", ou seja, os valores (ou palavras) que mais se repetem na base de dados. Se não houver repetição suficiente, a coluna é classificada como "Amodal".
4.  **Amostragem Interativa:** Após a análise, o programa pergunta no terminal se a pessoa deseja visualizar uma pequena amostra das primeiras e das últimas linhas de cada coluna, facilitando a conferência rápida do conteúdo da base de dados.

---

## Estrutura do Repositório

Os arquivos de código fonte que compõem este projeto são organizados da seguinte maneira:

*   **`main.cpp`**: O ponto de entrada da aplicação. Orquestra a leitura do arquivo, a execução das estatísticas e a exibição da amostragem no terminal.
*   **`DataAnalyzer.hpp` / `DataAnalyzer.cpp`**: Contêm a lógica matemática. Implementam as funções que calculam a média, mediana, moda, variância, desvio padrão e IQR. Nota: Utiliza a tecnologia OpenMP para processamento paralelo em alguns cálculos matemáticos.
*   **`DataHandler.hpp` / `DataHandler.cpp`**: Responsáveis por operações estruturais em vetores numéricos, implementando, de forma paralela via OpenMP, o algoritmo de ordenação *Merge Sort*, essencial para o cálculo rápido de medianas e quartis.
*   **`DataValidator.h` / `DataValidator.cpp`**: Arquivos utilitários que contêm a função capaz de validar se um texto (string) lido do arquivo é um número válido ou não.
*   **`FileData.hpp`**: Define as estruturas de dados fundamentais (`ColumnTables` e `FileData`) que o sistema utiliza para armazenar as colunas lidas do arquivo em memória de forma organizada.
*   **Licença (GPLv2)**: O projeto é distribuído de acordo com os termos da GNU General Public License versão 2.

---

## Instruções de Instalação e Execução (Para o Público Técnico)

### Pré-requisitos do Sistema

*   Um compilador C++ compatível com a linguagem e que possua suporte a **OpenMP** (como GCC ou Clang).
*   Terminal (Prompt de Comando, PowerShell, Linux Terminal ou macOS Terminal).
*   Um arquivo `.csv` na mesma estrutura esperada pelo programa.

### Compilação do Código

Para compilar o projeto manualmente através do terminal, garanta que todos os arquivos `.cpp` e os de cabeçalho (`.hpp` / `.h`) estejam no mesmo diretório.

Utilizando o GCC, o comando para compilação exige a flag `-fopenmp` para habilitar o suporte ao processamento paralelo que o código utiliza:

```bash
g++ -fopenmp main.cpp DataAnalyzer.cpp DataHandler.cpp DataValidator.cpp -o categorizador
```

### Executando a Aplicação

A execução do programa permite que você passe o caminho do arquivo CSV como argumento diretamente via linha de comando.

1.  **Execução com o arquivo padrão:**
    Se não for fornecido nenhum argumento, o sistema procurará, por padrão, um arquivo chamado `dataset_00_1000_sem_virg.csv` no diretório imediatamente superior (`../`).

    *   No Linux/macOS:
        ```bash
        ./categorizador
        ```
    *   No Windows:
        ```bash
        categorizador.exe
        ```

2.  **Execução especificando o arquivo CSV:**
    Você pode passar o nome ou caminho do seu próprio arquivo CSV. Lembre-se de que o sistema concatena `../` na frente do nome informado (ele procura um nível acima da pasta onde o programa foi executado).

    *   No Linux/macOS:
        ```bash
        ./categorizador meu_arquivo.csv
        ```
    *   No Windows:
        ```bash
        categorizador.exe meu_arquivo.csv
        ```

### Fluxo de Interação do Programa

*   Assim que executado com sucesso, o terminal exibirá as análises estatísticas por coluna.
*   Após a exibição, o terminal solicitará a entrada: `Gostaria de ver os dados amostrados das tabelas? (S/N):`. Digite `S` e pressione Enter para visualizar o cabeçalho e o final de cada coluna, ou `N` para finalizar.
*   Se optar pela visualização, a cada nova coluna o sistema perguntará se você quer ir para a próxima, até que todas tenham sido exibidas.
