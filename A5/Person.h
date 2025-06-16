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
    // Constructors
    Person();
    Person(std::string name, Date dob);

    // Getter methods
    std::string get_name() const;
    const Date& get_date_of_birth() const;

    // Setter methods
    Person *set_name(const std::string &new_name);
    Person *set_date_of_birth(Date &new_dob);

    // Print function
    void print_info() const;

    friend std::ostream& operator<<(std::ostream& os, Person& person);

    // Destructor
    ~Person();
};

#endif	// PERSON_H
