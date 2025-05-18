//
// Created by soma on 12/05/25.
//

#include "iostream"

// Function that take a string as input and finds the biggest plateau
void plateau() {
    char str[30] = "";
    std::cout << "Enter a string: ";
    std::cin.getline(str, 30);
    int size {};
    for (int i = 0; i < 30; i++) {
        if (str[i] == '\0') {
            size = i;
            break;
        }
    }
    int biggestConsecutive = 0;
    int consecutive = 0;
    char biggestChar = '0';
    char consChar = '0';
    /*
     Here we loop through the string and check of the character is the same as the previous one (stored in consChar).
        If it is, we add 1 to the consecutive variable.
        If it's not, we check if the consecutive variable is bigger than the biggestConsecutive variable.
        If it is, we set the biggestConsecutive variable to the consecutive variable and set the biggestChar variable to the current character.
        If it's not, we set the consecutive variable to 0.
     */
    for ( char letter : str) {
        consChar = letter;
        for (int i = 0; i < size; i++) {
            if (str[i] == consChar) {
                consecutive++;
            } else {
                if (consecutive > biggestConsecutive) {
                    biggestConsecutive = consecutive;
                    biggestChar = consChar;
                }
                consecutive = 0;
            }
        }
    }
    // We print the number of characters of the plateau
    std::cout << "Biggest plateau is ";
    for (auto i = 0; i < biggestConsecutive; i++) {
        std::cout << biggestChar;
    }
    std::cout << " of " << biggestConsecutive << " characters\n";
    // We print the address of the first letter of the plateau
    for (int i = 0; i < size; i++) {
        if (str[i] == biggestChar) {
            std::cout << "pointer to the first letter of the plateau: " << std::hex << static_cast<void*>(str+i) << "\n";
            break;
        }
    }
}

int main() {

    plateau();
    return 0;
}