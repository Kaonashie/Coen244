//
// Created by soma on 12/05/25.
//

#include "main.h"
#include "ApartmentSale.h"
#include "HouseSale.h"
#include "RealEstateManager.h"

int main() {
	auto customer_1 = new Customer("Marc", Date(02, 19, 2006), "124");
	auto customer_2 = new Customer("Evelyn", Date(07, 29, 1996), "125");

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
	 * Note IMPORTANT:
	 * Only deleting the manager here as it is responsible for the deletion of the properties and the agents.
	 * Manually deleting the agents and properties here doesn't make sense considering the manager owns them.
	 *
	 */
	delete manager;

	std::cout << "Program ended\n";
	return 0;
}