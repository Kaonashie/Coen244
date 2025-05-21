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

    auto* appt_request = new AppointmentRequest("Soma", "Rioux", "Monday");
    auto* patient = new Patient();

	auto* appt_request_2 = new AppointmentRequest("Soma", "James", "Tuesday");

    patient->set_name("Soma").set_date_of_birth(dob).set_medical_insurace_number("100");


    CM->insert_patient(patient);
    CM->insert_doctor(doctor);
    auto appt_time = CM->process_request(appt_request);
	auto appt_time_2 = CM->process_request(appt_request_2);
	patient->set_appointment_time(&appt_time);

	// TODO: Parse appointment times.
	std::cout << "Appointment succefully made for : " << *(patient->get_appointment_time()) << "\n";


    CM->print_patient_info(doctor->get_name());

    CM->cancel_appointment(doctor->get_name(),patient->get_name(), appt_time);


    delete CM;
    delete patient;
    delete doctor;
    return 0;
}