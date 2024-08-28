#include <iostream>
#include <string>

int main(){
    std::string products [100];
    int amount [100];
    int actual = 0;
    
    int i;
    for (i = 0; i < 100; i++) {
        amount[i] = 0;
    }

    std::cout << "Welcome to the store!" << std::endl;
    std::cout << "Type 'new' to create a new product and type the name of the product" << std::endl;
    std::cout << "Type 'add' to add a product to the stock and type the name of the product" << std::endl;
    std::cout << "Type 'show' to show the stock" << std::endl;
    std::cout << "Type 'remove' to remove a product from the stock and type the name of the product" << std::endl;
    std::cout << "Type 'delete' to delete a product from the list of products and type the name of the product" << std::endl;
    std::cout << "Type 'exit' to exit the program" << std::endl;
    
    while (true) {
        std::string command;
        std::cin >> command;
        if (command == "exit") {
            break;
        }
        if (command == "new"){
            std::string name;
            std::cin >> name;
            std::cout << "Creating new file: " << name << std::endl;
            products[actual] = name;
            actual++;
        }
        if (command == "add"){
            std::string name;
            std::cin >> name;
            for (int i = 0; i < actual; i++) {
                if (products[i] == name) {
                    amount[i] ++;
                    break;
                }
            }
        }
        if (command == "show"){
            for (int i = 0; i <= actual; i++) {
                std::cout << products[i] << " " << amount[i] << std::endl;
            }
        }
        if (command == "remove"){
            std::string name;
            std::cin >> name;
            for (int i = 0; i < actual; i++) {
                if (products[i] == name) {
                    amount[i] --;
                    break;
                }
            }
        }
        if (command == "delete"){
            std::string name;
            std::cin >> name;
            for (int i = 0; i < actual; i++) {
                if (products[i] == name) {
                    for (int j = i; j < actual - 1; j++) {
                        products[j] = products[j + 1];
                        amount[j] = amount[j + 1];
                    }
                    actual--;
                    break;
                }
            }
        }
    }
}