//
// Created by soma on 12/05/25.
//

#include "main.h"
#include "ClinicManager.h"
#include "AppointmentTime.h"
#include "AppointmentRequest.h"
#include "Date.h"
#include "Doctor.h"
#include "Patient.h"




int main() {

    auto* CM = new ClinicManager();
    auto* dob = new Date(02, 12, 2002);

    auto* doctor = new Doctor();
    doctor->set_name("Rioux");

	auto* doctor_2 = new Doctor();
	doctor_2->set_name("James");

    auto* patient = new Patient();
    patient->set_name("Soma").set_date_of_birth(dob).set_medical_insurace_number("100");

	auto* patient_2 = new Patient();
	patient_2->set_name("Marc").set_date_of_birth(dob).set_medical_insurace_number("101");

    auto* appt_request = new AppointmentRequest("Soma", "Rioux", "Monday");
    auto* appt_request_2 = new AppointmentRequest("Soma", "James", "Tuesday");
	auto* appt_request_3 = new AppointmentRequest("Marc", "Rioux", "Monday");

    CM->insert_patient(patient);
	CM->insert_patient(patient_2);
    CM->insert_doctor(doctor);
    CM->insert_doctor(doctor_2);


    auto appt_time = CM->process_request(appt_request);
    patient->set_appointment_time(&appt_time);


    auto appt_time_2 = CM->process_request(appt_request_2);

	auto appt_time_3 = CM->process_request(appt_request_3);
	patient_2->set_appointment_time(&appt_time_3);
	// TODO: Parse appointment times.
	std::cout << "Appointment succefully made for : " << *(patient->get_appointment_time()) << "\n";
	std::cout << "Appointment succefully made for : " << *(patient_2->get_appointment_time()) << "\n";



    CM->print_patient_info(doctor->get_name());

    CM->cancel_appointment(doctor->get_name(),patient->get_name(), appt_time);


    delete CM;
    delete patient;
    delete doctor;
    return 0;
}