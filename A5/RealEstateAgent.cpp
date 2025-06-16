//
// Created by soma on 02/06/25.
//

#include "RealEstateAgent.h"

RealEstateAgent::RealEstateAgent(std::string name, Date dob, int employee_id, Date employment_date)
    : Person(name, dob), employee_id(employee_id), employment_date(employment_date) {
    for (int i = 0; i < 20; i++) {
	properties[i] = nullptr;
    }
}
// Getter methods
int RealEstateAgent::get_employee_id() const { return employee_id; }
const Date& RealEstateAgent::get_employment_date() const { return employment_date; }

// Setter methods
void RealEstateAgent::set_employee_id(const int employee_id) { this->employee_id = employee_id; }
void RealEstateAgent::set_employment_date(const Date &employment_date) { this->employment_date = employment_date; }

// Adds property to array
bool RealEstateAgent::add_property(Property *prop) {
    if (prop == nullptr) {
        return false;
    }
    for (int i = 0; i < 20; i++) {
	if (properties[i] == nullptr) {
	    properties[i] = prop;
	    return true;
	}
    }
    return false;
}

// Removes property from array.
bool RealEstateAgent::remove_property(Property *prop) {
    if (prop == nullptr) {
        return false;
    }
    for (int i = 0; i < 20; i++) {
	if (properties[i] != nullptr && properties[i]->get_unique_id() == prop->get_unique_id()) {
	    properties[i] = nullptr;
	    return true;
	}
    }
    return false;
}

// Print function
void RealEstateAgent::print_info() const {
    Person::print_info();
    std::cout << "Employee ID: " << employee_id << "\n"
	      << "Employment Date: " << employment_date << "\n";
    std::cout << "Properties managed:\n";
    bool has_properties = false;
    for (int i = 0; i < 20; i++) {
	if (properties[i] != nullptr) {
	    std::cout << "  - Property ID: " << properties[i]->get_unique_id() << "\n";
	    has_properties = true;
	}
    }
    if (!has_properties) {
	std::cout << "  No properties assigned.\n";
    }
    std::cout << "\n";
}

// Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, RealEstateAgent& agent) {
    os << dynamic_cast<Person&>(agent)
    << "Employee id: " << agent.get_employee_id() << "\n"
    << "Employment Date: " << agent.get_employment_date() << "\n";
    return os;
}

 RealEstateAgent::~RealEstateAgent() {
    std::cout << "RealEstateAgent object destroyed successfully\n";
}
