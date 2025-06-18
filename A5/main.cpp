//
// Created by soma on 12/05/25.
//

#include "main.h"

#include "RealEstateManager.h"
#include "Customer.h"
#include "RealEstateAgent.h"
#include "HouseSale.h"
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
    auto customer2 = new Customer("James", Date(8, 17, 1998), "180");
    // Testing overloaded insertion operator for customer
    std::cout << *customer << std::endl;

    auto agent = new RealEstateAgent("Jake", Date(8, 31, 1995), 50, Date(12, 02, 2025));
    // Testing overloaded insertion operator on RealEstateAgent
    std::cout << *agent << std::endl;

    // Testing remove_property
    auto manager = new RealEstateManager();
    auto prop = new HouseSale();
    prop->set_listing_date(Date(02, 12, 2002));
    manager->insert_property(prop);
    if (manager->remove_property(Date(05, 13, 2002))) {
        std::cout << "Property removed\n\n";
    } else {
        std::cout << "Could not remove property\n\n";
    }
    // Test save person function
    manager->savePerson("people.txt", customer);
    manager->savePerson("people.txt", customer2);
    manager->savePerson("people.txt", agent);

    manager->searchPerson("people.txt", "Customer", "soma");
    manager->searchPerson("people.txt", "Customer", "James");
    manager->searchPerson("people.txt", "RealEstateAgent", "Jake");

    delete date_1;
    delete date_2;
    delete customer;
    delete agent;
    return 0;
}