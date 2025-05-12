//
// Created by soma on 12/05/25.
//

#include "Q4.h"


// TODO : Print the address of the first letter of the plateau
// TODO: Comment code
void plateau() {
    char str[30] = "";
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

    for ( char &letter : str) {
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
    std::cout << "Biggest plateau is ";
    for (auto i = 0; i < biggestConsecutive; i++) {
        std::cout << biggestChar;
    }
    std::cout << " of " << biggestConsecutive << " characters\n";
    for (int i = 0; i < size; i++) {
        if (str[i] == biggestChar) {
            std::cout << "pointer to the first letter of the plateau: " << std::hex << &*(str + i) << "\n";
            break;
        }
    }
}

int main() {

    plateau();
    return 0;
}