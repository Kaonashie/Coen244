//
// Created by soma on 02/06/25.
//

#ifndef LANDSALE_H
#define LANDSALE_H
#include "Property.h"


class LandSale : public Property {
private:
	std::string house_type;
	int year_built, no_rooms, sale_price;

public:
	LandSale(const std::string &address, const Customer &owner, int agent_id, const Date &listing_date,
			 const Date &sell_date, int sold_price, const std::string &house_type, int year_built, int no_rooms,
			 int sale_price) :
		Property(address, owner, agent_id, listing_date, sell_date, sold_price), house_type(house_type),
		year_built(year_built), no_rooms(no_rooms), sale_price(sale_price) {}
	std::string house_type1() const { return house_type; }
	int year_built1() const { return year_built; }
	int no_rooms1() const { return no_rooms; }
	int sale_price1() const { return sale_price; }
	~LandSale() override = default;
};


#endif // LANDSALE_H
