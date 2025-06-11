//
// Created by soma on 02/06/25.
//

#include "HouseSale.h"

// Constructors

HouseSale::HouseSale(std::string address, Customer customer, int agent_id, Date listing_date, Date sell_date,
					 int sold_price, std::string house_type, int year_build, int no_rooms): Property(address, customer, agent_id, listing_date, sell_date, sold_price), house_type(house_type), year_built(year_build), no_rooms(no_rooms) {}
HouseSale::~HouseSale() {
	std::cout << "HouseSale object destroyed successfully\n";
}
// Getter methods
std::string HouseSale::get_house_type() const {
	return house_type;
}
int HouseSale::get_year_built() const {
	return year_built;
}
int HouseSale::get_no_rooms() const {
	return no_rooms;
}
int HouseSale::get_sale_price() const {
	return sale_price;
}

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
HouseSale *HouseSale::set_house_type(std::string type) {
	this->house_type = type;
	return this;
}


// Print function
void HouseSale::print_info() const {
	Property::print_info();
	std::cout << "Year built: " << year_built << "\n"
	<< "House type: " << house_type << "\n"
	<< "Number of rooms: " << no_rooms << "\n"
	<< "Sale price: " << sale_price << "\n";
}


