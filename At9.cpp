#include <iostream>
#include <string>

int main(){
    std::string texto;
    std::cin >> texto;
    //paliandromo
    int i = 0;
    int j = texto.size() - 1;
    bool isPalindrome = true;
    while (i < j) {
        if (texto[i] != texto[j]) {
            isPalindrome = false;
            break;
        }
        i++;
        j--;
    }
    if (isPalindrome) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}