//
// Created by soma on 20/05/25.
//

#include "ClinicManager.h"

/**
 * Default constructor
 * Initializes an empty clinic with no patients, no doctors and zero appointments
 */
ClinicManager::ClinicManager() {
	this->patients = {};
	this->doctors = {};
	this->total_weekly_appointments = 0;
}

/**
 * Parameterized constructor
 * Initializes the clinic with given patients, doctors and total weekly appointments
 * 
 * @param patients Reference to an array of patient pointers
 * @param doctors Reference to an array of doctor pointers
 * @param total_weekly_appointments Total number of weekly appointments available in the clinic
 */
ClinicManager::ClinicManager(std::array<Patient *, 1000> &patients, std::array<Doctor *, 10> &doctors,
							 int total_weekly_appointments) {
	this->patients = patients;
	this->doctors = doctors;
	this->total_weekly_appointments = total_weekly_appointments;
}

/**
 * Gets the list of patients in the clinic
 * 
 * @return Array of patient pointers
 */
std::array<Patient *, 1000> ClinicManager::get_patients() const { return this->patients; }

/**
 * Gets the list of doctors in the clinic
 * 
 * @return Array of doctor pointers
 */
std::array<Doctor *, 10> ClinicManager::get_doctors() const { return this->doctors; }

/**
 * Gets the total number of weekly appointments in the clinic
 * 
 * @return Total weekly appointments
 */
int ClinicManager::get_total_weekly_appointments() const { return this->total_weekly_appointments; }

/**
 * Sets the list of patients in the clinic
 * 
 * @param patients Reference to an array of patient pointers to be set
 */
void ClinicManager::set_patients(std::array<Patient *, 1000> &patients) { this->patients = patients; }

/**
 * Sets the list of doctors in the clinic
 * 
 * @param doctors Reference to an array of doctor pointers to be set
 */
void ClinicManager::set_doctors(std::array<Doctor *, 10> &doctors) { this->doctors = doctors; }

/**
 * Sets the total number of weekly appointments in the clinic
 * 
 * @param twa Total weekly appointments to be set
 */
void ClinicManager::set_total_weekly_appointments(int twa) { this->total_weekly_appointments = twa; }

/**
 * Gets the index corresponding to the day of the week
 * 
 * @param day The day of the week as a string
 * @return The index corresponding to the day (0 for Monday, 1 for Tuesday, etc.)
 */
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

/**
 * Inserts a new patient into the clinic system
 * Checks if the patient already exists to avoid duplicates
 * Adds the patient to the first available slot in the patients array
 * 
 * @param p_new Pointer to the patient object to be inserted
 */
void ClinicManager::insert_patient(Patient *p_new) {
	for (Patient *&p: this->patients) {
		if (p == p_new) {
			std::cout << "Patient already exists \n";
			return;
		}
	}
	for (Patient *&p: this->patients) {
		if (p == nullptr) {
			std::cout << "Adding patient \n";
			p = p_new;
			return;
		}
	}
}

/**
 * Inserts a new doctor into the clinic system
 * Checks if the doctor already exists to avoid duplicates
 * Adds the doctor to the first available slot in the doctors array
 * 
 * @param d_new Reference to pointer of the doctor to be inserted
 */
void ClinicManager::insert_doctor(Doctor *&d_new) {
	for (Doctor *&d: this->doctors) {
		if (d == d_new) {
			std::cout << "Doctor already exists \n";
			return;
		}
	}
	for (Doctor *&d: this->doctors) {
		if (d == nullptr) {
			std::cout << "Adding doctor \n";
			d = d_new;
			return;
		}
	}
}

/**
 * Processes an appointment request and schedules if possible
 * Locates patient and doctor, checks availability, and finds an open time slot
 * Updates doctor's appointment schedule and returns appointment details
 * 
 * @param r Pointer to the appointment request
 * @return Dynamically allocated AppointmentTime object with scheduling details
 *         (returns AppointmentTime with "Invalid" if scheduling fails)
 */
AppointmentTime *ClinicManager::process_request(AppointmentRequest *r) {
	Patient *reqPatient = find_patient(r->get_patient_name());
	Doctor *reqDoctor = find_doctor(r->get_doctor_name());

	if (reqPatient == nullptr || reqDoctor == nullptr) {
		std::cout << "Either a patient or doctor was not found \n";
		return new AppointmentTime{"Invalid", 0, 0};
	}

	if (reqPatient->get_appointment_time() != nullptr) {
		std::cout << "Patient already has an appointment \n";
		return new AppointmentTime{"Invalid", 0, 0};
	}
	int h, m;
	std::string day = r->get_day();
	int index = this->get_index(day);
	auto appts = reqDoctor->get_appointments();
	for (int i = 0; i < 12; i++) {
		if (appts[index][i] == nullptr) {
			std::cout << "Found an empty slot\n";
			appts[index][i] = reqPatient;
			reqDoctor->set_appointments(appts); // Stays for now
			reqPatient->set_doctor_name(reqDoctor->get_name());
			this->add_num_weekly_appointment();

			// Calculate the time slot based on the index
			if (i < 6) { // Morning slots: 0, 1, 2, 3, 4, 5
				h = 9 + (i / 2);
				m = (i % 2 == 0) ? 0 : 30;
			} else { // Afternoon slots: 6, 7, 8, 9, 10, 11
				h = 14 + ((i - 6) / 2);
				m = ((i - 6) % 2 == 0) ? 0 : 30;
			}

			return new AppointmentTime{day, h, m};
		}
	}

	return new AppointmentTime{"Invalid", 0, 0};
}

/**
 * Finds a doctor in the clinic system by name
 * 
 * @param d_name The name of the doctor to search for
 * @return Pointer to the doctor if found, nullptr otherwise
 */
Doctor *ClinicManager::find_doctor(std::string d_name) const {
	for (Doctor *d: this->doctors) { // Iterate over actual member array, not a copy
		if (d != nullptr && d->get_name() == d_name) {
			return d;
		}
	}
	return nullptr;
}

/**
 * Finds a patient in the clinic system by name
 * 
 * @param p_name The name of the patient to search for
 * @return Pointer to the patient if found, nullptr otherwise
 */
Patient *ClinicManager::find_patient(std::string p_name) const {
	for (Patient *p: this->patients) { // Iterate over actual member array, not a copy
		if (p != nullptr && p_name == p->get_name()) {
			return p;
		}
	}
	return nullptr;
}

/**
 * Increments the count of total weekly appointments by one
 */
void ClinicManager::add_num_weekly_appointment() { this->total_weekly_appointments++; }

/**
 * Decrements the count of total weekly appointments by one
 */
void ClinicManager::remove_num_weekly_appointment() { this->total_weekly_appointments--; }

/**
 * Cancels an existing appointment
 * Removes the appointment from doctor's schedule and clears the appointment from patient record
 * 
 * @param d_name Doctor's name
 * @param p_name Patient's name
 * @param appt_time_ptr Pointer to the appointment time to be cancelled
 */
void ClinicManager::cancel_appointment(std::string d_name, std::string p_name, AppointmentTime *appt_time_ptr) {
	Patient *patient_to_cancel = find_patient(p_name);
	Doctor *doctor = find_doctor(d_name);

	if (patient_to_cancel == nullptr || doctor == nullptr) {
		std::cout << "Either a patient or doctor was not found for cancellation\\\\n";
		return;
	}

	int index = get_index(appt_time_ptr->get_day());
	auto appts = doctor->get_appointments();
	for (int i = 0; i < 12; i++) {
		if (appts[index][i] == patient_to_cancel) {
			std::cout << "Found and deleted an appointment\n";
			appts[index][i] = nullptr;
			doctor->set_appointments(appts);
			this->remove_num_weekly_appointment();
			patient_to_cancel->set_appointment_time(nullptr);
			std::cout << "Appointment details cleared from patient object: " << p_name << "\n";

			return;
		}
	}
}

/**
 * Prints information about all patients with appointments for a specific doctor
 * 
 * @param d_name Doctor's name whose patient information to print
 */
void ClinicManager::print_patient_info(std::string d_name) const {
	Doctor *doctor = find_doctor(d_name);
	if (doctor == nullptr) {
		std::cout << "Doctor not found \n";
		return;
	}
	auto appts = doctor->get_appointments();
	for (auto i: appts) {
		for (auto patient: i) {
			if (patient != nullptr) {
				std::cout << "Patient's name : " << patient->get_name() << "\n";
				std::cout << "Patient's medical insurance number : " << patient->get_medical_insurance_number() << "\n";
			}
		}
	}
}

/**
 * Destructor - cleans up all dynamically allocated objects
 * Deletes all patient and doctor objects in the arrays
 */
ClinicManager::~ClinicManager() {
	for (Patient *&p: this->patients) {
		delete p;
	}
	for (Doctor *&d: this->doctors) {
		delete d;
	}
	std::cout << "ClinicManager object destroyed successfully \n";
}
