//
// Created by soma on 12/05/25.
//

#include "Q3.h"


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
    int result = 0;
    int temp = 0;

    for (int i = 0; i < size; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9') {
            // std::cout << "Numbers before index: " << std::endl;
            // int sliced = slice(str, tempIndex, i);
            // std::cout << "Slice: " << sliced << std::endl;

            // tempIndex = i+1;
            if (temp == 0) {
                if (str[i] == '*') {
                    std::cout << str[i-1] << " Mult by " << str[i+1] << "\n";
                    result = (str[i-1] - '0') * (str[i+1] - '0');
                    std::cout << result;
                    std::cout << "\n";


                } else if (str[i] == '/') {
                    std::cout << str[i-1] << " Divided by " << str[i+1] << "\n";
                    result = (str[i-1] - '0') / (str[i+1] - '0');
                    std::cout << result;
                    std::cout << "\n";



                } else if (str[i] == '-') {
                    std::cout << str[i-1] << " Minus " << str[i+1] << "\n";
                    result = (str[i-1] - '0') - (str[i+1] - '0');

                    std::cout << result;
                    std::cout << "\n";


                } else if (str[i] == '+') {
                    std::cout << str[i-1] << " Plus " << str[i+1] << "\n";
                    result = (str[i-1] - '0') + (str[i+1] - '0');

                    std::cout << result;
                    std::cout << "\n";

                }
                temp = 1;

            } else {
                if (str[i] == '*') {
                    std::cout << result << " Mult by " << str[i+1] << "\n";
                    result *= (str[i+1] - '0');
                    std::cout << result;
                    std::cout << "\n";

                } else if (str[i] == '/') {
                    std::cout << result << " Divided by " << str[i+1] << "\n";
                    result /= (str[i+1] - '0');
                    std::cout << result;
                    std::cout << "\n";


                } else if (str[i] == '-') {
                    std::cout << result << " Minus " << str[i+1] << "\n";
                    result -= (str[i+1] - '0');

                    std::cout << result;
                    std::cout << "\n";

                } else if (str[i] == '+') {
                    std::cout << result << " Plus " << str[i+1] << "\n";
                    result += (str[i+1] - '0');

                    std::cout << result;
                    std::cout << "\n";

                }
            }
        }
    }

}


int main() {
    operation();
    return 0;
}