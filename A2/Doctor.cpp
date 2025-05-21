//
// Created by soma on 20/05/25.
//

#include "Doctor.h"

Doctor::Doctor() {
    for (std::array d : this->appointments) {
        for (Patient* p : d) {
            p = nullptr;
        }
    }
    this->name = "";
}

std::string Doctor::get_name() const {
    return this->name;
}

std::array<std::array<Patient *, 12>, 5> Doctor::get_appointments() const {
    return this->appointments;
}

Doctor& Doctor::set_name(const std::string &name) {
    this->name = name;
    return *this;
}

Doctor& Doctor::set_appointments(std::array<std::array<Patient *, 12>, 5> &appointments) {
    this->appointments = appointments;
    return *this;
}

Doctor::~Doctor() {
    std::cout << "Doctor object destroyed successfully \n";
}