#include "Q1.h"

// Function that takes a string as input and counts the frequency of each letter in the string
void frequency() {
    // String to hold the input (Max size is 30)
    char str[30] = "";
    std::cout << "Enter a string: ";
    std::cin >> str;
    // Input validation
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' || str[i] > 'z' ) {
            std::cout << "Invalid input. Only lowercase letters are allowed.\n";
            return;
        }
    }
    // Array of length 26 to store all possible lowercase letters.
    int char_count[26] = {0};
    // Count the frequency of each letter in the string
    for (char j : str) {
        char_count[j - 'a']++;
    }
    /*
     Here we loop through the counted array of letters.
     We check if the count at the current index is greater than the count at the "greatest count index" (max_j)
     If it is, we make the greatest count index equal to the current index.
     If it's not, we continue.
     When the inner loop is done, we verify that the count at the current max index is not zero, if it is we break.
     Then we print the output by using the max index + 'a' to reconvert the character.
     */
    int max_j = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (char_count[j] > char_count[max_j]) {
                max_j = j;
            }
        }
        if (char_count[max_j] == 0)
            break;
        std::cout << static_cast<char>(max_j + 'a') << " : " << char_count[max_j] << "\n";
        char_count[max_j] = 0;
    }
}

// Main function that calls the frequency function.
int main() {
    frequency();
    return 0;
}