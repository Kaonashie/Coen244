//
// Created by soma on 26/05/25.
//

#include "Person.h"

// Constructors
Person::Person() : date_of_birth(Date()) {}

Person::Person(std::string name, Date dob) {
    this->name = name;
    this->date_of_birth = dob;
}

// Getter methods
std::string Person::get_name() const { return this->name; }
// Returning a const Date reference to reduce copying
const Date& Person::get_date_of_birth() const { return this->date_of_birth; }

// Setter methods
Person *Person::set_name(const std::string &new_name) {
    this->name = new_name;
    return this;
}

Person *Person::set_date_of_birth(Date &new_dob) {
    this->date_of_birth = new_dob;
    return this;
}

// Print function
void Person::print_info() const {
    std::cout << "Name: " << name << "\n"
	      << "Date of birth: " << this->date_of_birth << "\n";
}

// Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, Person& person) {
    os << "Name: " << person.get_name() << "\n"
    << "Date of birth: " << person.get_date_of_birth() << "\n";
    return os;
}

// Destructor
Person::~Person() { std::cout << "Person object successfully destroyed.\n"; }
