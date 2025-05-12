//
// Created by soma on 12/05/25.
//

#include "Q3.h"

int STRING_SIZE = 30;

// TODO : Order of operations???
int slice(char *str, int start, int end) {
    int slice_size = end - start;
    char sliced[slice_size];
    int number = 0;
    int i = 0;
    for (int j = start; j < end; j++) {
        sliced[i++] = str[j];
    }
    for (int i = 0; i < slice_size; i++) {
        number = number * 10 + (sliced[i] - '0');
    }
    return number;
}

void operation() {
    char str[30] = "4+5*3/2";
    // std::cout << "Enter a string: ";
    // std::cin >> str;
    int size {};

    for (int i = 0; i < 30; i++) {
        if (str[i] == '\0') {
            size = i;
            break;
        }
    }
    float result = 0;
    int temp = 0;
    int number_of_ops = 0;
    int number_of_numbers = 0;
    char operations[30] = "";
    char numbers[30] = "";
    // Extract numbers and operations
    for (int i = 0; i < size; i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            operations[number_of_ops++] = str[i];
        } else {
            numbers[number_of_numbers++] = str[i];
        }
    }
    // Add a null terminator to the end of the numbers array
    float lhs{}, rhs{};
    // Start by doing the first multiplication and division
    for (int i = 0; i < number_of_ops; i++) {
        if (operations[i] == '*') {
                lhs = (numbers[i] - '0');
                rhs = (numbers[i+1] - '0');
                result = result +  lhs * rhs;
                break;
        } else if (operations[i] == '/') {
            lhs = (numbers[i] - '0');
            rhs = (numbers[i+1] - '0');
            result = lhs / rhs;
            break;
        }
    }
    std::cout << result << std::endl;

    // Once first multiplication and division is done, we can do the rest
    // Run through multiplaction and divisions
    bool skip = true;
    for (int i = 0; i < number_of_ops; i++) {
        if (operations[i] == '*') {
            if (skip) {
                skip = false;
                continue;
            }
            lhs = result;
            rhs = (numbers[i+1] - '0');
            result = lhs * rhs;
        } else if (operations[i] == '/') {
            if (skip) {
                skip = false;
                continue;
            }
            lhs = result;
            rhs = (numbers[i+1] - '0');
            result = lhs / rhs;
        }
    }
    // Run through addition and subtraction
    for (int i = 0; i < number_of_ops; i++) {
        if (operations[i] == '+') {
            rhs = numbers[i] - '0';
            result += rhs;
        } else if (operations[i] == '-') {
            rhs = (numbers[i] - '0');
            result -= rhs;
        }
    }

    std::cout << result << std::endl;

}


int main() {
    operation();
    return 0;
}