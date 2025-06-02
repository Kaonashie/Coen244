//
// Created by soma on 02/06/25.
//

#ifndef REALESTATEMANAGER_H
#define REALESTATEMANAGER_H
#include "RealEstateAgent.h"


class RealEstateManager {
private:
	RealEstateAgent* agents[30];
	Property* properties_for_sale[1000];
	Property *properties_sold[500];
public:
	RealEstateManager();
	~RealEstateManager();
	void insert_agent(RealEstateAgent* agent);
	void insert_property(Property* property);
	void sold_house(Property* property, int price, Date date_of_sale);
	void print_property_info(int id) const;
	void print_agent_properties(int agent_id) const;
	void print_all_properties() const;
};



#endif //REALESTATEMANAGER_H
