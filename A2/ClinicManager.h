//
// Created by soma on 20/05/25.
//

#ifndef CLINICMANAGER_H
#define CLINICMANAGER_H
#include <array>
#include "Patient.h"
#include "Doctor.h"
#include "AppointmentTime.h"
#include "AppointmentRequest.h"


class ClinicManager {
private:
    std::array<Patient*, 1000> patients{};
    std::array<Doctor*, 10> doctors{};
    int total_weekly_appointments;
public:
    ClinicManager();
    ClinicManager(std::array<Patient*, 1000> &patients, std::array<Doctor*, 10> &doctors, int total_weekly_appointments);

    std::array<Patient*, 1000> get_patients() const;
    std::array<Doctor*, 10> get_doctors() const;
    int get_total_weekly_appointments() const;

    void set_patients(std::array<Patient*, 1000> &patients);
    void set_doctors(std::array<Doctor*, 10> &doctors);
    void set_total_weekly_appointments(int twa);

    void insert_patient(Patient* p_new);
    void insert_doctor(Doctor* &d_new);
    AppointmentTime* process_request(AppointmentRequest *r);
    void cancel_appointment(std::string d_name, std::string p_name, AppointmentTime &appt_time);
    void print_patient_info(std::string d_name) const;
	void add_num_weekly_appointment();
	void remove_num_weekly_appointment();


    int get_index(std::string day);
    Doctor* find_doctor(std::string d_name) const;
    Patient* find_patient(std::string p_name) const;

    ~ClinicManager();
};



#endif //CLINICMANAGER_H
