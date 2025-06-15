//
// Created by soma on 04/06/25.
//

#include "LandSale.h"

LandSale::LandSale(std::string address, Customer customer, int agent_id, Date listing_date, Date sell_date,
		   int sold_price, double area_of_land, int sale_price)
    : Property(address, customer, agent_id, listing_date, sell_date, sold_price),
      area_of_land(area_of_land),
      sale_price(sale_price) {}

// Getter methods
double LandSale::get_area_of_land() const { return this->area_of_land; }
int LandSale::get_sale_price() const { return this->sale_price; }

// Setter methods
LandSale *LandSale::set_area_of_land(double area) {
    this->area_of_land = area;
    return this;
}
LandSale *LandSale::set_sale_price(int price) {
    this->sale_price = price;
    return this;
}

// Print function
void LandSale::print_info() const {
    Property::print_info();
    std::cout << "Sale price: " << sale_price << "\n"
	      << "Area of land: " << area_of_land << "\n";
}

// Destructor
LandSale::~LandSale() { std::cout << "LandSale object destroyed successfully.\n"; }
