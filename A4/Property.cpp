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
				   const Date &sell_date, int sold_price) :
	unique_id(unique_id), address(address), owner(owner), agent_id(agent_id), listing_date(listing_date),
	sell_date(sell_date), sold_price(sold_price) {
	unique_id = counter;
	counter++;
}
