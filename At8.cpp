#include <iostream>

int main(){
    int numbers[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> numbers[i][j];
        }
    }
    int diagonalSum = 0;
    for (int i = 0; i < 3; i++) {
        diagonalSum += numbers[i][i];
    }
    std::cout << diagonalSum << std::endl;
}