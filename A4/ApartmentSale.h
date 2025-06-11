//
// Created by soma on 02/06/25.
//

#ifndef APARTMENTSALE_H
#define APARTMENTSALE_H
#include "Property.h"

class ApartmentSale : public Property {
private:
	double condo_fees;
	int year_built, no_rooms, sale_price;

public:
	// Constructors
	ApartmentSale();
	ApartmentSale(const std::string &address, const Customer &owner, int agent_id, const Date &listing_date,
				  const Date &sell_date, int sold_price, double condo_fees, int year_built, int no_rooms,
				  int sale_price) :
		Property(address, owner, agent_id, listing_date, sell_date, sold_price), condo_fees(condo_fees),
		year_built(year_built), no_rooms(no_rooms), sale_price(sale_price) {}

	// Destructor
	~ApartmentSale();

	// Getter methods
	double get_condo_fees() const;
	int get_year_built() const;
	int get_no_rooms() const;
	virtual int get_sale_price() const;

	// Setter methods
	void set_condo_fees(double condo_fees);
	void set_year_built(int year_built);
	void set_no_rooms(int no_rooms);
	void set_sale_price(int sale_price);

	// Print function
	virtual void print_info() const;
};

#endif // APARTMENTSALE_H
