//
// Created by soma on 12/05/25.
//

#include "Q2.h"

void symmetric() {
    char str[30] = "";
    std::cout << "Enter a string: ";
    std::cin >> str;
    int size {};
    for (int i = 0; i < 30; i++) {
        if (str[i] == '\0') {
            size = i;
            break;
        }
    }
    std::cout << size << " characters\n";
    for (int i = 0; i < size; i++) {
        if (str[i] != str[size - i - 1]) {
            std::cout << "Not symmetric\n";
            return;
        }
    }
    std::cout << "Symmetric\n";
}


int main() {
    symmetric();
    return 0;
}