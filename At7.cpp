#include <iostream>

int main(){
    int numbers [] = {7, 2, 5, 6, 1};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << std::endl;
    }
}