#include <iostream>
#include <chrono>   // Inclui a biblioteca para medição de tempo

// Função para alocar dinamicamente uma matriz N x N
int** alocaMatriz(int N) {
    // Aloca um array de ponteiros para as linhas da matriz
    int** matriz = new int*[N];
    // Para cada linha, aloca um array de inteiros de tamanho N
    for (int i = 0; i < N; ++i) {
        matriz[i] = new int[N];
    }

    return matriz;
}

// Função para preencher a matriz com valores e calcular a soma dos elementos
int somaMatriz(int** matriz, int N, int value) {
    int soma = 0;
    // Preenche a matriz com valores e calcula a soma
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (value > 0) {
                matriz[i][j] = value;  // Exemplo de preenchimento: matriz[i][j] = value
            } else {
                matriz[i][j] = i + j;  // Exemplo de preenchimento: matriz[i][j] = i + j
            }
            soma += matriz[i][j];
        }
    }
    return soma;
}

// Função para liberar a memória alocada dinamicamente
void liberaMatriz(int** matriz, int N) {
    // Libera a memória de cada linha
    for (int i = 0; i < N; ++i) {
        delete[] matriz[i];
    }
    // Libera a memória do array de ponteiros
    delete[] matriz;
}

int main() {
    int N = 10;  // Define o tamanho da matriz
    int value = 0; // Define o valor a ser somado

    // Aloca a matriz
    int** matriz = alocaMatriz(N);

    // Preenche a matriz e calcula a soma de seus elementos
    int soma = somaMatriz(matriz, N, value);

    // Imprime a soma total dos elementos
    std::cout << "A soma de todos os elementos da matriz é: " << soma << std::endl;

    // Libera a memória alocada
    liberaMatriz(matriz, N);

    return 0;  // Retorna 0, indicando que o programa terminou com sucesso.
}