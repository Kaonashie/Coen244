//
// Created by soma on 12/05/25.
//

#include "main.h"

#include "RealEstateAgent.h"
#include "Customer.h"

int main() {

    auto date_1 = new Date(02, 02, 2002);
    auto date_2 = new Date(02, 12, 2005);
    // Test overloaded greater than operator
    if (*date_2 > *date_1) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    auto customer = new Customer("soma", Date(12, 02, 2002), "1001");
    // Testing overloaded insertion operator for customer
    std::cout << *customer << std::endl;

    auto agent = new RealEstateAgent("Jake", Date(31, 8, 1995), 50, Date(12, 02, 2025));
    // Testing overloaded insertion operator on RealEstateAgent
    std::cout << *agent << std::endl;


    delete date_1;
    delete date_2;
    delete customer;
    delete agent;
    return 0;
}