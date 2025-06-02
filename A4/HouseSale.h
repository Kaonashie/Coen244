//
// Created by soma on 02/06/25.
//

#ifndef HouseSale_H
#define HouseSale_H
#include "Property.h"


class HouseSale : public Property {
private:
	std::string house_type;
	int year_built{}, no_rooms{}, sale_price{};

public:
	HouseSale(const std::string &address, const Customer &owner, int agent_id, const Date &listing_date,
			 const Date &sell_date, int sold_price, const std::string &house_type, int year_built, int no_rooms,
			 int sale_price) :
		Property(address, owner, agent_id, listing_date, sell_date, sold_price), house_type(house_type),
		year_built(year_built), no_rooms(no_rooms), sale_price(sale_price) {}
	std::string house_type1() const { return house_type; }
	int get_year_built() const { return year_built; }
	int get_no_rooms() const { return no_rooms; }

	HouseSale();

	HouseSale* set_year_built(int n_year);
	HouseSale* set_no_rooms(int n_rooms);
	HouseSale* set_sale_price(int sale_price);
	virtual int get_sale_price() const {return sale_price;};

	~HouseSale() override = default;
};


#endif // HouseSale_H
