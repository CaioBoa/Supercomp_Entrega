#include <iostream>

int main(){
    int numbers [10];
    for (int i = 0; i < 10; i++) {
        std::cin >> numbers[i];
    }
    int highest = numbers[0];
    for (int i = 1; i < 10; i++) {
        if (numbers[i] > highest) {
            highest = numbers[i];
        }
    }
    std::cout << highest << std::endl;
}