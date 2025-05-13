//
// Created by soma on 12/05/25.
//

#include "Q3.h"

int STRING_SIZE = 30;

// Function that takes a string as input and evaluates the expression
void operation() {
    char str[30] = "9*3+5/2-8";
    // std::cout << "Enter a string: ";
    // std::cin >> str;
    double num = 0;
    char op = '+';
    double total = 0;
    double last = 0;
    /*
    Here we loop through the string and check if the character is number or operator.
    If it's a number, we convert multiply the current number by 10 and add the new number that we convert to an integer
    to account for multiple digit number.
    If it's an operator, we check on the last operator (that is store in op) and do the operation on the last number (stored in last).
    If it's a + or -, we add the number to the total and set the last number to that current number.
    If it's a *, we multiply the last number by the current number. Same for /.
    Finally, we add the last number to the total.
    The operator is set to + first so that last is set the first number.

    This respect order of operation because the multiplication and division never touch the total, only the last variable.
    So we are doing the multiplication and division in a separate variable and then we add it to the total.
    */
    for (char c : str) {
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        } else {
            switch (op) {
                case '+':
                    total += last;
                    last = num;
                    break;
                case '-':
                    total += last;
                    last = -num;
                    break;
                case '*':
                    last *= num;
                    break;
                case '/':
                    last /= num;
                    break;
                default:
                    break;
            }
            op = c;
            num = 0;
        }
    }

    total += last;
    std::cout << total << std::endl;
}


int main() {
    operation();
    return 0;
}