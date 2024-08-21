#include <iostream>
#include <stdexcept>  // Para exceções

class Vector {
public:
    // Construtor que inicializa o vetor com tamanho inicial
    inline Vector(int tamanho)
        : tam(0), capacidade(tamanho) {
        dados = new int[capacidade];
    }

    // Destrutor para liberar a memória alocada dinamicamente
    inline ~Vector() {
        delete[] dados;
    }

    // Inicializa o vetor com um valor específico
    inline void inicializa(int valor) {
        for (int i = 0; i < capacidade; ++i) {
            dados[i] = valor;
        }
        tam = capacidade;
    }

    // Retorna o valor no índice especificado
    inline int get(int index) const {
        if (index < 0 || index >= tam) {
            throw std::out_of_range("Índice fora do intervalo.");
        }
        return dados[index];
    }

    // Define um valor no índice especificado
    inline void set(int index, int valor) {
        if (index < 0 || index >= tam) {
            throw std::out_of_range("Índice fora do intervalo.");
        }
        dados[index] = valor;
    }

    // Insere um valor no índice especificado, redimensionando se necessário
    void inserir(int index, int valor) {
        if (index < 0 || index > tam) {
            throw std::out_of_range("Índice fora do intervalo.");
        }
        if (tam == capacidade) {
            redimensiona(2 * capacidade);
        }
        for (int i = tam; i > index; --i) {
            dados[i] = dados[i - 1];
        }
        dados[index] = valor;
        ++tam;
    }

    // Remove o valor no índice especificado
    void remover(int index) {
        if (index < 0 || index >= tam) {
            throw std::out_of_range("Índice fora do intervalo.");
        }
        for (int i = index; i < tam - 1; ++i) {
            dados[i] = dados[i + 1];
        }
        --tam;
    }

    // Multiplica todos os elementos do vetor por um escalar
    void multiplicaPorEscalar(int escalar) {
        for (int i = 0; i < tam; ++i) {
            dados[i] *= escalar;
        }
    }

    // Imprime o vetor
    inline void imprime() const {
        for (int i = 0; i < tam; ++i) {
            std::cout << dados[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int* dados;
    int tam;
    int capacidade;

    // Redimensiona o vetor para uma nova capacidade
    void redimensiona(int novaCapacidade) {
        int* novosDados = new int[novaCapacidade];
        for (int i = 0; i < tam; ++i) {
            novosDados[i] = dados[i];
        }
        delete[] dados;
        dados = novosDados;
        capacidade = novaCapacidade;
    }
};

int main() {
    Vector vec(5);
    vec.inicializa(1);  // Inicializa o vetor com valor 1
    vec.imprime();

    vec.inserir(2, 10);  // Insere o valor 10 na posição 2
    vec.imprime();

    vec.remover(3);  // Remove o elemento na posição 3
    vec.imprime();

    vec.multiplicaPorEscalar(5);  // Multiplica todos os elementos por 5
    vec.imprime();

    return 0;
}