#include <iostream>   // Inclui a biblioteca padrão de entrada e saída, usada para operações como std::cout.
#include <fstream>    // Inclui a biblioteca para manipulação de arquivos, usada para ler e escrever arquivos.
#include <vector>     // Inclui a biblioteca de vetores, usada para armazenar e manipular listas de números.

// Declaração de funções:

// Função que lê números de um arquivo e os armazena em um vetor.
void lerArquivo(const std::string& nomeArquivo, std::vector<int>& numeros){
    std::ifstream arquivo(nomeArquivo); // Abre o arquivo para leitura.

    if (!arquivo.is_open()) { // Verifica se o arquivo foi aberto corretamente.
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return;
    }

    int numero;
    while (arquivo >> numero) { // Lê cada número do arquivo e armazena no vetor.
        numeros.push_back(numero);
    }

    arquivo.close(); // Fecha o arquivo após a leitura.
}

// Função que dobra os valores de um vetor de números, passando o vetor original por referência.
void dobrarValoresReferencia(const std::vector<int>& numerosOriginais, std::vector<int>& numerosDobrados) {
    numerosDobrados.clear(); // Limpa o vetor de destino antes de adicionar novos valores.
    for (int num : numerosOriginais) {
        numerosDobrados.push_back(num * 2); // Dobra cada número e adiciona ao vetor de destino.
    }
}

// Função que dobra os valores de um vetor de números, passando o vetor original por ponteiro.
void dobrarValoresPonteiro(const std::vector<int>* numerosOriginais, std::vector<int>* numerosDobrados) {
    if (numerosOriginais == nullptr || numerosDobrados == nullptr) {
        std::cerr << "Erro: Vetor original ou vetor de destino é um ponteiro nulo." << std::endl;
        return;
    }
    numerosDobrados->clear(); // Limpa o vetor de destino antes de adicionar novos valores.
    for (int num : *numerosOriginais) {
        numerosDobrados->push_back(num * 2); // Dobra cada número e adiciona ao vetor de destino.
    }
}

// Função que escreve os números de um vetor em um arquivo.
void escreverArquivo(const std::string& nomeArquivo, const std::vector<int>& numeros) {
    std::ofstream arquivo(nomeArquivo); // Abre o arquivo para escrita.

    if (!arquivo.is_open()) { // Verifica se o arquivo foi aberto corretamente.
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return;
    }

    for (int num : numeros) {
        arquivo << num << std::endl; // Escreve cada número em uma nova linha do arquivo.
    }

    arquivo.close(); // Fecha o arquivo após a escrita.
}

// Implementação das funções...

int main() {
    // Declaração de dois vetores de inteiros: um para armazenar os números lidos do arquivo e outro para armazenar os números dobrados.
    std::vector<int> numeros, numerosDobrados;

    // Chama a função para ler os números do arquivo "entrada.txt" e armazena-os no vetor 'numeros'.
    lerArquivo("entrada.txt", numeros);

    // Chama a função que dobra os valores do vetor 'numeros' usando passagem por referência e armazena o resultado no vetor 'numerosDobrados'.
    dobrarValoresReferencia(numeros, numerosDobrados);

    // Chama a função que escreve os números do vetor 'numerosDobrados' no arquivo "saida_referencia.txt".
    escreverArquivo("saida_referencia.txt", numerosDobrados);

    // Chama a função que dobra os valores do vetor 'numeros' usando passagem por ponteiro e armazena o resultado no vetor 'numerosDobrados'.
    dobrarValoresPonteiro(&numeros, &numerosDobrados);

    // Chama a função que escreve os números do vetor 'numerosDobrados' no arquivo "saida_ponteiro.txt".
    escreverArquivo("saida_ponteiro.txt", numerosDobrados);

    // Retorna 0, indicando que o programa terminou com sucesso.
    return 0;
}
