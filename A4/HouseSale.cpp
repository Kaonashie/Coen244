//
// Created by soma on 02/06/25.
//

#include "HouseSale.h"

// Constructors
HouseSale::HouseSale() {}

// Setter methods
HouseSale *HouseSale::set_year_built(int n_year) {
	this->year_built = n_year;
	return this;
}

HouseSale *HouseSale::set_no_rooms(int n_rooms) {
	this->no_rooms = n_rooms;
	return this;
}

HouseSale *HouseSale::set_sale_price(int sale_price) {
	this->sale_price = sale_price;
	return this;
}

