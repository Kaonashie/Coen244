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
	auto lands = new LandSale();


	auto agent = new RealEstateAgent("Soma", Date(12, 02, 2002), 2002, Date(02, 05, 2025));
	manager->insert_agent(agent);

	apt->set_agent_id(agent->get_employee_id());
	house->set_agent_id(agent->get_employee_id());
	lands->set_agent_id(agent->get_employee_id());

	manager->insert_property(apt);
	manager->insert_property(house);
	manager->insert_property(lands);
	manager->print_all_lands();

	manager->sold_house(apt, 10000, Date(02,12,2002));

	/**
	 * Note :
	 * Only deleting the manager here as it is responsible for the deletion of the properties and the agents.
	 *
	 *
	 *
	 */
	delete manager;
	return 0;
}