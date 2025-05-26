//
// Created by soma on 12/05/25.
//

#include "main.h"
#include "AppointmentRequest.h"
#include "AppointmentTime.h"
#include "ClinicManager.h"
#include "Date.h"
#include "Doctor.h"
#include "Patient.h"

/**
 * Returns false if the appointment time is invalid, true otherwise.
 *
 * @param appt_time pointer to an AppointmentTime object
 * @return true of false
 */
bool validate_appointment(AppointmentTime* appt_time) {
	if (appt_time->get_day() == "Invalid"){
        std::cout << "Invalid appointment time. \n";
		return false;
    }
	return true;
}

/**
 * Driver program for the medical clinic scheduling system.
 * This program creates a clinic manager, adds doctors and patients,
 * processes appointment requests, and manages appointments.
 */
int main() {

    // Create a ClinicManager instance
	auto *CM = new ClinicManager();

    // Create some sample data for testing
	auto *dob = new Date(02, 12, 2002);
    auto *dob_2 = new Date(03, 12, 2002);

    // Create doctors and patients
	auto *doctor = new Doctor();
	doctor->set_name("Rioux");

	auto *doctor_2 = new Doctor();
	doctor_2->set_name("James");

	auto *patient = new Patient();
	patient->set_name("Soma").set_date_of_birth(dob).set_medical_insurance_number("100");

	auto *patient_2 = new Patient();
	patient_2->set_name("Marc").set_date_of_birth(dob_2).set_medical_insurance_number("101");

    // Create appointment requests
	auto appt_request = new AppointmentRequest("Soma", "Rioux", "Monday");
    /**
     * AppointmentRequest that has the same patient name as the first one to demonstrate
     * that the system will not allow multiple appointments for the same patient
     */
	auto appt_request_2 = new AppointmentRequest("Soma", "James", "Tuesday");
	auto appt_request_3 = new AppointmentRequest("Marc", "Rioux", "Monday");

    // Process appointment requests and manage appointments
	CM->insert_patient(patient);
	CM->insert_patient(patient_2);
	CM->insert_doctor(doctor);
	CM->insert_doctor(doctor_2);


    // Process the first appointment request for the same patient (should succeed)
	auto *appt_time = CM->process_request(appt_request);
    if (validate_appointment(appt_time)) 
        patient->set_appointment_time(appt_time);
    
    // Process the second appointment request for the same patient (should fail)
	auto *appt_time_2 = CM->process_request(appt_request_2);
    if (validate_appointment(appt_time_2))
        patient->set_appointment_time(appt_time);

    // Process the third appointment request for a different patient (should succeed)
	auto *appt_time_3 = CM->process_request(appt_request_3);
    if (validate_appointment(appt_time_3))
        patient_2->set_appointment_time(appt_time_3);

    // Print appointment times for both patients
	std::cout << "Appointment succefully made for : " << *(patient->get_appointment_time()) << "\n";
	std::cout << "Appointment succefully made for : " << *(patient_2->get_appointment_time()) << "\n";


    // Print the doctors's patient information
	CM->print_patient_info(doctor->get_name());

    // Cancel an appointment
	CM->cancel_appointment(doctor->get_name(), patient->get_name(), appt_time);


    /**
     * Delete the dynamically allocated objects to prevent memory leaks
     * CM will delete the patients and doctors in its destructor
     * The AppointmentTime objects are not deleted here because they are managed by the Patient objects
     * The AppointmentRequest objects deleted here as well 
     */
	delete CM;
	delete appt_request;
	delete appt_request_2;
	delete appt_request_3;
	std::cout << "Program finished successfully \n";
	return 0;
}
