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
	double get_area_of_land() { return area_of_land;}
	int get_sale_price() const {return sale_price;}
};



#endif //LANDSALE_H
