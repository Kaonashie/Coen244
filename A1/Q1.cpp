#include "Q1.h"


// Class that represents a letter, it's name and the frequency it's found in a string.
class Letter {
public:
    char name{};
    int count = 0;
    Letter() : name('a'), count(0) {}
    Letter(char name) : name(name) {}
};
// Comparison function for sorting letters by their frequency
bool compare(Letter &a, Letter &b) {
    return a.count > b.count;
}
// Class that represents an array of Letters
class LetterArray {
public:
    // Array of Letters
    Letter letters[26];
    // Constructor that initializes the letters array with the letters a-z
    LetterArray(): letters{} {
        for (int i = 0; i < 26; i++) {
            letters[i] = Letter('a' + i);
        }
    }

    // Method that goes through the letters array and adds 1 to the count of the letter that matches the input character
    void add(char letter) {
        for (auto &l : letters) {
            if (l.name == letter) {
                l.count++;
                return;
            }
        }
    }

    // Method that sorts the Letter array by the frequency (count) of the letters using the comapare function defined above
    void sort() {
        std::sort(letters, letters + 26, compare);
    }
    // Method that prints the letters and their frequency
    void print() {
        for (auto &l : letters) {
            if (l.count > 0) {
                std::cout << l.name << ": " << l.count << "\n";
            }
        }
    }
};

// Function that takes a string as input and counts the frequency of each letter in the string
void frequency() {
    // Array of valid characters for input validation
    char inputstr[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    // String to hold the input (Max size is 30)
    char str[30] = "";
    std::cout << "Enter a string: ";
    std::cin >> str;
    // Input validation
    for (int i = 0; str[i] != '\0'; i++) {
        bool found = false;
        for (int j = 0; j < 26; j++) {
            if (str[i] == inputstr[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "Invalid character: " << str[i] << "\n";
            return;
        }
    }
    // Create a LetterArray object and add the letters to it
    LetterArray letterArray;
    for (char character : str) {
        letterArray.add(character);
    }
    std::cout << "Frequency of each character in the string:\n";
    // Sort and print the array of letters
    letterArray.sort();
    letterArray.print();
}

// Main function that calls the frequency function.
int main() {
    frequency();
    return 0;
}