#include "Q1.h"

class Letter {
public:
    char name{};
    int count = 0;
    Letter() : name('a'), count(0) {}
    Letter(char name) : name(name) {}
};
bool compare(Letter &a, Letter &b) {
    return a.count > b.count;
}

class LetterArray {
public:
    Letter letters[26];
    LetterArray(): letters{} {
        for (int i = 0; i < 26; i++) {
            letters[i] = Letter('a' + i);
        }
    }

    void add(char letter) {
        for (auto &l : letters) {
            if (l.name == letter) {
                l.count++;
                return;
            }
        }
    }

    void sort() {
        std::sort(letters, letters + 26, compare);
    }

    void print() {
        for (auto &l : letters) {
            if (l.count > 0) {
                std::cout << l.name << ": " << l.count << "\n";
            }
        }
    }
};


void frequency() {
    char str[30] = "";
    std::cout << "Enter a string: ";
    std::cin >> str;
    LetterArray letterArray;
    for (char character : str) {
        letterArray.add(character);
    }
    std::cout << "Frequency of each character in the string:\n";
    letterArray.sort();
    letterArray.print();
}


int main() {
    frequency();
    return 0;
}