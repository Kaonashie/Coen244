//
// Created by soma on 04/06/25.
//

#ifndef LANDSALE_H
#define LANDSALE_H
#include "Property.h"


class LandSale: public Property {
private:
	double area_of_land;
	int sale_price;
public:
	// Constructors
	LandSale(std::string address = "", Customer customer = Customer(), int agent_id = 0, Date listing_date = Date(), Date sell_date = Date(), int sold_price = 0, double area_of_land = 0, int sale_price = 0);

	// Getter functions
	double get_area_of_land() const;
	int get_sale_price() const;

	// Setter functions
	LandSale* set_area_of_land(double area);
	LandSale* set_sale_price(int price);

	virtual void print_info() const;

	~LandSale();

};



#endif //LANDSALE_H
