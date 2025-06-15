//
// Created by soma on 02/06/25.
//
#include "Property.h"

// Static member initialization
int Property::counter = 0;

// Constructors
Property::Property() {
    unique_id = counter;
    counter++;
}

Property::Property(const std::string &address, const Customer &owner, int agent_id, const Date &listing_date,
		   const Date &sell_date, int sold_price)
    : address(address),
      owner(owner),
      agent_id(agent_id),
      listing_date(listing_date),
      sell_date(sell_date),
      sold_price(sold_price) {
    unique_id = counter;
    counter++;
}

// Getter methods
int Property::get_unique_id() const { return unique_id; }
std::string Property::get_address() const { return address; }
Customer Property::get_owner() const { return owner; }
int Property::get_agent_id() const { return agent_id; }
Date Property::get_listing_date() const { return listing_date; }
Date Property::get_sell_date() const { return sell_date; }
int Property::get_sold_price() const { return sold_price; }


// Setter methods
void Property::set_unique_id(int unique_id) { this->unique_id = unique_id; }
void Property::set_address(const std::string &address) { this->address = address; }
void Property::set_owner(const Customer &owner) { this->owner = owner; }
void Property::set_agent_id(int agent_id) { this->agent_id = agent_id; }
void Property::set_listing_date(const Date &listing_date) { this->listing_date = listing_date; }
void Property::set_sell_date(const Date &sell_date) { this->sell_date = sell_date; }
void Property::set_sold_price(int sold_price) { this->sold_price = sold_price; }

// Print function
void Property::print_info() const {
    std::cout << "Property ID: " << unique_id << "\n"
	      << "Address: " << address << "\n"
	      << "Owner: " << owner.get_name() << "\n"
	      << "Agent ID: " << agent_id << "\n"
	      << "Listing Date: " << listing_date << "\n"
	      << "Sell Date: " << sell_date << "\n"
	      << "Sold Price: " << sold_price << "\n";
}


// Destructor
 Property::~Property() { std::cout << "Property object destroyed successfully.\n"; }
