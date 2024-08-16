#include <iostream>

int main(){
    int numbers[5];
    for (int i = 0; i < 5; i++) {
        std::cin >> numbers[i];
    }
    int result = 0;
    for (int i = 0; i < 5; i++) {
        result += numbers[i];
    }
    std::cout << result << std::endl;
}