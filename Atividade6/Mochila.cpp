#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Item {
    int peso;
    int valor;
};

struct Mochila {
    int valor;
    int capacidade;
};

Mochila calculaMochila(const std::vector<Item>& items, int capacidade) {
    if (items.empty()) {
        return {0, capacidade};
    }
    std::vector<Item> itemsRestantes(items.begin() + 1, items.end());
    Mochila MochilaNo = calculaMochila(itemsRestantes, capacidade);
    Mochila MochilaYes = calculaMochila(itemsRestantes, capacidade - items[0].peso);
    MochilaYes.valor += items[0].valor;
    if (items[0].peso > capacidade) {
        return MochilaNo;
    }
    return MochilaNo.valor > MochilaYes.valor ? MochilaNo : MochilaYes;
}

int main() {
    std::ifstream infile("entrada3.txt");
    if (!infile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo" << std::endl;
        return 1;
    }

    int capacidade, n;
    infile >> n >> capacidade;

    std::vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        infile >> items[i].peso >> items[i].valor;
    }

    infile.close();

    std::cout << "Capacidade da mochila: " << capacidade << std::endl;

    Mochila final = calculaMochila(items, capacidade);

    std::cout << "Valor máximo que pode ser obtido: " << final.valor << std::endl;
    std::cout << "Capacidade restante: " << final.capacidade << std::endl;

    return 0;
}