//
// Created by soma on 02/06/25.
//

#include "Customer.h"

// Constructors
Customer::Customer(std::string name, Date dob, std::string social_insurance_number)
    : Person(name, dob), social_insurance_number(social_insurance_number) {}

// Getter methods
std::string Customer::get_social_insurance_number() const { return social_insurance_number; }

// Setter methods
void Customer::set_social_insurance_number(const std::string &social_insurance_number) {
    this->social_insurance_number = social_insurance_number;
}

// Print function
void Customer::print_info() const {
    Person::print_info();
    std::cout << "Social insurance number: " << social_insurance_number << "\n";
}

// Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, Customer& customer) {
    os << dynamic_cast<Person&>(customer)
    << "Social insurance number: " << customer.get_social_insurance_number() << "\n";
    return os;
}

// Destructor
Customer::~Customer() { std::cout << "Customer object destroyed successfully\n"; }
