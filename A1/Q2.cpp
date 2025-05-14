#include "Q2.h"

// Function that checks if a string is symmetric
void symmetric() {
    char str[30] = "";
    std::cout << "Enter a string: ";
    std::cin.getline(str, 30);
    int size {};
    // Get the size of the string
    for (int i = 0; i < 30; i++) {
        if (str[i] == '\0') {
            size = i;
            break;
        }
    }
    std::cout << size << " characters\n";
    // Check if the string is symmetric by looking at the opposite index
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