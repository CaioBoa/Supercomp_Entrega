#include <iostream>

int main() {
    int first_number;
    int second_number;
    char operato;
    std::cin >> first_number >> second_number >> operato;
    switch (operato) {
        case '+':
            std::cout << first_number + second_number << std::endl;
            break;
        case '-':
            std::cout << first_number - second_number << std::endl;
            break;
        case '*':
            std::cout << first_number * second_number << std::endl;
            break;
        case '/':
            std::cout << first_number / second_number << std::endl;
            break;
        default:
            std::cout << "Invalid operator" << std::endl;
    }
    return 0;
}