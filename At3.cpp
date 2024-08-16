#include <iostream>

int main(){
    int number;
    std::cin >> number;
    if (number % 2 == 0) {
        std::cout << "Even" << std::endl;
    } else {
        std::cout << "Odd" << std::endl;
    }
    return 0;
}