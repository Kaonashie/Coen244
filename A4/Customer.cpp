//
// Created by soma on 02/06/25.
//

#include "Customer.h"

Customer::Customer() : Person("", Date()), social_insurance_number("") {}


void Customer::set_social_insurance_number(const std::string &social_insurance_number) {
	this->social_insurance_number = social_insurance_number;
}
