#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

std::string toLower(const std::string &str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

int main() {
    std::string filename;
    std::cout << "Digite o nome do arquivo: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    std::string line;
    int numLines = 0;
    int numWords = 0;
    std::map<std::string, int> wordCount;
    while (std::getline(file, line)) {
        numLines++;
        std::istringstream lineStream(line);
        std::string word;
        while (lineStream >> word) {
            word = toLower(word);
            wordCount[word]++;
            numWords++;
        }
    }

    file.close();

    double avgWordsPerLine = static_cast<double>(numWords) / numLines;
    std::string mostCommonWord;
    int maxCount = 0;

    for (const auto &entry : wordCount) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            mostCommonWord = entry.first;
        }
    }

    std::cout << "Numero de linhas: " << numLines << std::endl;
    std::cout << "Numero de palavras: " << numWords << std::endl;
    std::cout << "Media de palavras por linha: " << avgWordsPerLine << std::endl;
    std::cout << "Palavra mais comum: " << mostCommonWord << " (aparece " << maxCount << " vezes)" << std::endl;

    return 0;
}