//
// Created by soma on 20/05/25.
//

#include "ClinicManager.h"

ClinicManager::ClinicManager() {
    this->patients = {};
    this->doctors = {};
    this->total_weekly_appointments = 0;
}

ClinicManager::ClinicManager(std::array<Patient *, 1000> &patients, std::array<Doctor *, 10> &doctors,
                             int total_weekly_appointments) {
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

void ClinicManager::set_patients(std::array<Patient *, 1000> &patients) {
    this->patients = patients;
}

void ClinicManager::set_doctors(std::array<Doctor *, 10> &doctors) {
    this->doctors = doctors;
}

void ClinicManager::set_total_weekly_appointments(int twa) {
    this->total_weekly_appointments = twa;
}

int ClinicManager::get_index(std::string day) {
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

    return index;
}

void ClinicManager::insert_patient(Patient *p_new) {
    for (Patient * &p: this->patients) {
        if (p == p_new) {
            std::cout << "Patient already exists \n";
            return;
        }
    }
    for (Patient * &p: this->patients) {
        if (p == nullptr) {
            std::cout << "Adding patient \n";
            p = p_new;
            return;
        }
    }
}

void ClinicManager::insert_doctor(Doctor * &d_new) {
    for (Doctor * &d: this->doctors) {
        if (d == d_new) {
            std::cout << "Patient already exists \n";
            return;
        }
    }
    for (Doctor * &d: this->doctors) {
        if (d == nullptr) {
            std::cout << "Adding doctor \n";
            d = d_new;
            return;
        }
    }
}

AppointmentTime ClinicManager::process_request(AppointmentRequest *r) {
    Patient *reqPatient = find_patient(r->get_patient_name());
    Doctor *reqDoctor = find_doctor(r->get_doctor_name());

    if (reqPatient == nullptr || reqDoctor == nullptr) {
        std::cout << "Either a patient or doctor was not found \n";
        return AppointmentTime{"Invalid", 0, 0};
    }

	if (reqPatient->get_appointment_time() != nullptr) {
		std::cout << "Patient already has an appointment \n";
		return AppointmentTime{"Invalid", 0, 0};
	}

    std::string day = r->get_day();
    int index = this->get_index(day);
    auto appts = reqDoctor->get_appointments();
    for (int i = 0; i < 12; i++) {
        if (appts[index][i] == nullptr) {
            std::cout << "Found an empty slot\n";
            appts[index][i] = reqPatient;
            reqDoctor->set_appointments(appts);
            reqPatient->set_doctor_name(reqDoctor->get_name());
        	this->add_num_weekly_appointment();
            return AppointmentTime{day, i, 0};
        }
    }

    return AppointmentTime{"Invalid", 0, 0};
}

Doctor* ClinicManager::find_doctor(std::string d_name) const {
    for (Doctor * &d: this->get_doctors()) {
        if (d != nullptr && d->get_name() == d_name) {
            return d;
        }
    }
    return nullptr;
}

Patient* ClinicManager::find_patient(std::string p_name) const {
    for (Patient * &p: this->get_patients()) {
        if (p != nullptr && p_name == p->get_name()) {
            return p;
        }
    }
    return nullptr;
}

 void ClinicManager::add_num_weekly_appointment() {
	this->total_weekly_appointments++;
}

void ClinicManager::remove_num_weekly_appointment() {
	this->total_weekly_appointments--;
}


void ClinicManager::cancel_appointment(std::string d_name, std::string p_name, AppointmentTime &appt_time) {
    Patient *patient = find_patient(p_name);
    Doctor *doctor = find_doctor(d_name);


    if (patient == nullptr || doctor == nullptr) {
        std::cout << "Either a patient or doctor was not found \n";
        return;
    }

    int index = get_index(appt_time.get_day());
	auto appts = doctor->get_appointments();
    for (int i = 0; i < 12; i++) {
        if (appts[index][i] == patient) {
            std::cout << "Found and deleted an appointment\n";
            appts[index][i] = nullptr;
            doctor->set_appointments(appts);
        	this->remove_num_weekly_appointment();
            return;
        }
    }
}

void ClinicManager::print_patient_info(std::string d_name) const {
    Doctor *doctor = find_doctor(d_name);
    auto appts = doctor->get_appointments();
    for (auto i : appts) {
        for (auto patient : i) {
            if (patient != nullptr) {
                std::cout << "Patient's name : " << patient->get_name() << "\n";
                std::cout << "Patient's medical insurance number : " << patient->get_medical_insurance_number()<< "\n";
            }
        }
    }
}

ClinicManager::~ClinicManager() {
    std::cout << "ClinicManager object destroyed successfully \n";
}
