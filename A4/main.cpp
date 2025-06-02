//
// Created by soma on 12/05/25.
//

#include "main.h"


#include "ApartmentSale.h"
#include "HouseSale.h"
#include "RealEstateManager.h"

int main() {

	auto apt = new ApartmentSale();
	auto house = new HouseSale();
	auto manager = new RealEstateManager();

	manager->insert_property(apt);
	manager->insert_property(house);


    return 0;
}