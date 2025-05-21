//
// Created by soma on 20/05/25.
//

#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <array>
#include <string>
#include "Patient.h"


class Doctor {
private:
    std::string name;
    std::array<std::array<Patient*, 12>, 5> appointments{};
public:
    Doctor();

    std::string get_name() const;
    std::array<std::array<Patient*, 12>, 5> get_appointments() const;

    Doctor& set_name(const std::string &name);
    Doctor& set_appointments(std::array<std::array<Patient*, 12>, 5> &appointments);

    ~Doctor();

};



#endif //DOCTOR_H
