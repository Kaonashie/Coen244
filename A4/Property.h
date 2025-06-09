//
// Created by soma on 02/06/25.
//

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Customer.h"

class Property {
private:
	static int counter;
	int unique_id{};
	std::string address;
	Customer owner;
	int agent_id{};
	Date listing_date;
	Date sell_date;
	int sold_price{};

public:
	// Constructors
	Property();
	Property(const std::string &address, const Customer &owner, int agent_id, const Date &listing_date,
			 const Date &sell_date, int sold_price);

	// Destructor
	virtual ~Property() = default;

	// Pure virtual function
	virtual int get_sale_price() const = 0;

	// Getter methods
	int get_unique_id() const;
	std::string get_address() const;
	Customer get_owner() const;
	int get_agent_id() const;
	Date get_listing_date() const;
	Date get_sell_date() const;
	int get_sold_price() const;

	// Setter methods
	void set_unique_id(int unique_id);
	void set_address(const std::string &address);
	void set_owner(const Customer &owner);
	void set_agent_id(int agent_id);
	void set_listing_date(const Date &listing_date);
	void set_sell_date(const Date &sell_date);
	void set_sold_price(int sold_price);
};

#endif // PROPERTY_H
