//
// Created by soma on 20/05/25.
//

#include "Patient.h"

Patient::Patient() {
    this->date_of_birth = new Date();
    this->appointment_time = nullptr;
    this->name = "";
    this->doctor_name = "";
    this->medical_insurance_number = "";
}

Patient::Patient(Date *dob, AppointmentTime *appt_time, const std::string &name, const std::string &d_name, const std::string &med_ins_num) {
    this->date_of_birth = dob;
    this->appointment_time = appt_time;
    this->name = name;
    this->doctor_name = d_name;
    this->medical_insurance_number = med_ins_num;
}

const Date* Patient::get_date_of_birth() const {
    return this->date_of_birth;
}

const AppointmentTime *Patient::get_appointment_time() const {
    return this->appointment_time;
}

std::string Patient::get_name() const {
    return this->name;
}

std::string Patient::get_doctor_name() const {
    return this->doctor_name;
}

std::string Patient::get_medical_insurance_number() const {
    return this->medical_insurance_number;
}


Patient& Patient::set_date_of_birth(Date *dob) {
    this->date_of_birth = dob;
    return *this;
}

Patient& Patient::set_appointment_time(AppointmentTime *appt_time) {
    this->appointment_time = appt_time;
    return *this;
}

Patient& Patient::set_doctor_name(const std::string &d_name) {
    this->doctor_name = d_name;
    return *this;
}

Patient& Patient::set_name(const std::string &name) {
    this->name = name;
    return *this;
}

Patient& Patient::set_medical_insurace_number(const std::string &med_ins_num) {
    this->medical_insurance_number = med_ins_num;
    return *this;
}

Patient::~Patient() {
    delete date_of_birth;
    //delete appointment_time;
    std::cout << "Patient object destroyed successfully \n";
}