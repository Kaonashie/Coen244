//
// Created by soma on 26/05/25.
//

#ifndef HOSPITALMANAGER_H
#define HOSPITALMANAGER_H
#include <array>
#include <iostream>

#include "Doctor.h"
#include "Patient.h"


class HospitalManager {
private:
	std::array<Doctor, 12> doctors;
	std::array<Patient, 100> patients;
};



#endif //HOSPITALMANAGER_H
