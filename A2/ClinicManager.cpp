//
// Created by soma on 20/05/25.
//

#include "ClinicManager.h"

ClinicManager::ClinicManager() {
    this->patients = {};
    this->doctors = {};
    this->total_weekly_appointments = 0;
}

ClinicManager::ClinicManager(std::array<Patient *, 1000> &patients, std::array<Doctor *, 10> &doctors, int total_weekly_appointments) {
    this->patients = patients;
    this->doctors = doctors;
    this->total_weekly_appointments = total_weekly_appointments;
}

std::array<Patient *, 1000> ClinicManager::get_patients() const {
    return this->patients;
}

std::array<Doctor *, 10> ClinicManager::get_doctors() const {
    return this->doctors;
}

int ClinicManager::get_total_weekly_appointments() const {
    return this->total_weekly_appointments;
}

void ClinicManager::set_patients(std::array<Patient*, 1000> &patients) {
    this->patients = patients;
}

void ClinicManager::set_doctors(std::array<Doctor *, 10> &doctors) {
    this->doctors = doctors;
}

void ClinicManager::set_total_weekly_appointments(int twa) {
    this->total_weekly_appointments = twa;
}

void ClinicManager::insert_patient(Patient* p_new) {
    for (Patient* &p : this->patients) {
        if (p == p_new) {
            std::cout << "Patient already exists \n";
            return;
        }
    }
    for (Patient* &p : this->patients) {
        if (p == nullptr) {
            std::cout << "Adding patient \n";
            p = p_new;
            return;
        }
    }
}

void ClinicManager::insert_doctor(Doctor* &d_new) {
    for (Doctor* &d : this->doctors) {
        if (d == d_new) {
            std::cout << "Patient already exists \n";
            return;
        }
    }
    for (Doctor* &d : this->doctors) {
        if (d == nullptr) {
            std::cout << "Adding doctor \n";
            d = d_new;
            return;
        }
    }
}

AppointmentTime ClinicManager::process_request(AppointmentRequest* r) {

    Patient* reqPatient = nullptr;
    for (Patient* p: this->patients) {
        if (p != nullptr && p->get_name() == r->get_patient_name()) {
            reqPatient = p;
            std::cout << "found patient\n";
            break;
        }
    }
    for (Doctor* &d : this->doctors) {
        if (d != nullptr) {
            if (r->get_doctor_name() == d->get_name()) {
                std::cout << "Found doctor \n";
                std::string day = r->get_day();
                int index = 0;
                if (day == "Monday") {
                    index = 0;
                } else if (day == "Tuesday") {
                    index = 1;
                } else if (day == "Wednesday") {
                    index = 2;
                } else if (day == "Thursday") {
                    index = 3;
                } else if (day == "Friday") {
                    index = 4;
                }
                auto appts = d->get_appointments();
                for (int i =0; i < 12; i++) {
                    if (appts[index][i] == nullptr) {
                        std::cout << "Found an empty slot\n";
                        appts[index][i] = reqPatient;
                        d->set_appointments(appts);
                        return AppointmentTime(day, i, 0);
                    }
                }
            }
        }
    }
    return AppointmentTime("Invalid", 0, 0);
}


ClinicManager::~ClinicManager() {
    std::cout << "ClinicManager object destroyed successfully \n";
}
