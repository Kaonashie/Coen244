//
// Created by soma on 20/05/25.
//

#ifndef CLINICMANAGER_H
#define CLINICMANAGER_H
#include <array>
#include "AppointmentRequest.h"
#include "AppointmentTime.h"
#include "Doctor.h"
#include "Patient.h"


/**
 * ClinicManager Class
 * Central management system for the medical clinic.
 * Handles patient and doctor records, appointment scheduling, and appointment cancellation.
 * Maintains arrays of Patient and Doctor objects and tracks the total weekly appointments.
 */
class ClinicManager {
private:
	std::array<Patient *, 1000> patients{};  // Array to store patient records (max 1000)
	std::array<Doctor *, 10> doctors{};      // Array to store doctor records (max 10)
	int total_weekly_appointments;           // Counter for total appointments in the week

public:
	// Default constructor - initializes empty clinic
	ClinicManager();
	
	// Parameterized constructor - creates clinic with predefined data
	ClinicManager(std::array<Patient *, 1000> &patients, std::array<Doctor *, 10> &doctors,
				  int total_weekly_appointments);

	// Getter methods
	std::array<Patient *, 1000> get_patients() const;
	std::array<Doctor *, 10> get_doctors() const;
	int get_total_weekly_appointments() const;

	// Setter methods
	void set_patients(std::array<Patient *, 1000> &patients);
	void set_doctors(std::array<Doctor *, 10> &doctors);
	void set_total_weekly_appointments(int twa);

	// Core clinic management functions
	void insert_patient(Patient *p_new);                                        // Add new patient to the system
	void insert_doctor(Doctor *&d_new);                                         // Add new doctor to the system
	AppointmentTime process_request(AppointmentRequest *r);                    // Schedule an appointment
	void cancel_appointment(std::string d_name, std::string p_name, AppointmentTime *appt_time); // Cancel an appointment
	void print_patient_info(std::string d_name) const;                          // Print patient info for a doctor
	
	// Appointment counter management
	void add_num_weekly_appointment();                                          // Increment appointment counter
	void remove_num_weekly_appointment();                                       // Decrement appointment counter

	// Helper methods
	int get_index(std::string day);                                             // Convert day name to array index
	Doctor *find_doctor(std::string d_name) const;                              // Find doctor by name
	Patient *find_patient(std::string p_name) const;                            // Find patient by name

	// Destructor - releases memory for all patients and doctors
	~ClinicManager();
};


#endif // CLINICMANAGER_H
