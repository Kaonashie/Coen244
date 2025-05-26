//
// Created by soma on 26/05/25.
//

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "Date.h"


class Person {
private:
	std::string name;
	Date date_of_birth;
public:
	Person();
	Person(std::string name, Date dob);

	std::string get_name() const;
	Date get_date_of_birth() const;

	Person* set_name(const std::string &new_name);
	Person* set_date_of_birth(Date &new_dob);

	~Person();
};



#endif //PERSON_H
