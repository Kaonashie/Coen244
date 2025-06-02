//
// Created by soma on 26/05/25.
//

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "Date.h"

/**
 * Person class.
 * Base class from which to derive other type of persons. Has a name and a date of birth member variable.
 * Provides functions to get, set and print member variables.
 */
class Person {
private:
	std::string name;
	Date date_of_birth;

public:
	// Constructors
	Person();
	Person(std::string name, Date dob);

	// Getters
	std::string get_name() const;
	Date get_date_of_birth() const;

	// Setters
	Person *set_name(const std::string &new_name);
	Person *set_date_of_birth(Date &new_dob);

	// Print
	void print_info() const;

	// Destructor
	~Person();
};

#endif // PERSON_H
