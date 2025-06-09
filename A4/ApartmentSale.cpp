//
// Created by soma on 02/06/25.
//

#include "ApartmentSale.h"

// Constructors
ApartmentSale::ApartmentSale() : Property() {}

// Getter methods
double ApartmentSale::get_condo_fees() const {
	return condo_fees;
}
int ApartmentSale::get_year_built() const {
	return year_built;
}
int ApartmentSale::get_no_rooms() const {
	return no_rooms;
}
int ApartmentSale::get_sale_price() const {
	return sale_price;
}

// Setter methods
void ApartmentSale::set_condo_fees(double condo_fees) {
	this->condo_fees = condo_fees;
}
void ApartmentSale::set_year_built(int year_built) {
	this->year_built = year_built;
}
void ApartmentSale::set_no_rooms(int no_rooms) {
	this->no_rooms = no_rooms;
}
void ApartmentSale::set_sale_price(int sale_price) {
	this->sale_price = sale_price;
}