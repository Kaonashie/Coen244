//
// Created by soma on 26/05/25.
//

#include "Person.h"
/**
 * Default constructor
 */
Person::Person() : date_of_birth(Date()) {}

/**
 * Parameterized constructor
 * @param name name of the person
 * @param dob date of birth of the person
 */
Person::Person(std::string name, Date dob) {
	this->name = name;
	this->date_of_birth = dob;
}

/**
 * Gets the person's name.
 * @return person's name as a string
 */
std::string Person::get_name() const { return this->name; }

/**
 * Get the person's date of birth
 * @return person's date of birth as a Date object
 */
Date Person::get_date_of_birth() const { return this->date_of_birth; }

/**
 * Sets a new name.
 * @param new_name new name as a string
 * @return Person* to allow cascading.
 */
Person *Person::set_name(const std::string &new_name) {
	this->name = new_name;
	return this;
}

/**
 * Sets a new date of birth
 * @param new_dob new date of birth.
 * @return Person* to allow cascading.
 */
Person *Person::set_date_of_birth(Date &new_dob) {
	this->date_of_birth = new_dob;
	return this;
}

/**
 * Prints the person's information.
 */
void Person::print_info() const {
	std::cout << "Name: " << name << "\n"
			  << "Date of birth: " << this->date_of_birth << "\n";
}

/**
 * Destructor.
 */
Person::~Person() { std::cout << "Person object successfully destroyed.\n"; }
