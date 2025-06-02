//
// Created by soma on 02/06/25.
//

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Customer.h"


class Property {
private:
	static int counter;
	int unique_id;
	std::string address;
	Customer owner;
	int agent_id;
	Date listing_date;
	Date sell_date;
	int sold_price;

public:
	Property(const std::string &address, const Customer &owner, int agent_id, const Date &listing_date,
			 const Date &sell_date, int sold_price);
	virtual ~Property() = default;
	virtual int get_sale_price() const = 0;
	int get_unique_id() const { return unique_id; }
	void set_unique_id(const int unique_id) { this->unique_id = unique_id; }
	std::string get_address() const { return address; }
	void set_address(const std::string &address) { this->address = address; }
	Customer get_owner() const { return owner; }
	void set_owner(const Customer &owner) { this->owner = owner; }
	int get_agent_id() const { return agent_id; }
	void set_agent_id(const int agent_id) { this->agent_id = agent_id; }
	Date get_listing_date() const { return listing_date; }
	void set_listing_date(const Date &listing_date) { this->listing_date = listing_date; }
	Date get_sell_date() const { return sell_date; }
	void set_sell_date(const Date &sell_date) { this->sell_date = sell_date; }
	int get_sold_price() const { return sold_price; }
	void set_sold_price(const int sold_price) { this->sold_price = sold_price; }
};



#endif // PROPERTY_H
