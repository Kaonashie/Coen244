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

    patient->set_name("Soma").set_date_of_birth(dob);


    CM->insert_patient(patient);
    CM->insert_doctor(doctor);
    auto appt_time = CM->process_request(appt_request);
    patient->set_appointment_time(&appt_time);

    CM->print_patient_info(doctor->get_name());

    CM->cancel_appointment(doctor->get_name(),patient->get_name(), appt_time);
    delete CM;
    delete patient;
    delete doctor;
    return 0;
}