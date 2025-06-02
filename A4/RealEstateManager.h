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
	RealEstateManager() = default;
	~RealEstateManager() = default;
	void insert_agent(RealEstateAgent agent);
	void insert_property(Property* property);
};



#endif //REALESTATEMANAGER_H
