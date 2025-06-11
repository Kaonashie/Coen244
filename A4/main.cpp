//
// Created by soma on 12/05/25.
//

#include "main.h"

#include "ApartmentSale.h"
#include "HouseSale.h"
#include "RealEstateManager.h"

int main() {

    // Create apartment, house and land sale objects
    auto apt = new ApartmentSale();
    auto house = new HouseSale();
    auto land = new LandSale();
    // Set some information for printing later
    land->set_sale_price(100000);
    land->set_address("Montreal");
    land->set_listing_date(Date(10, 9, 2025));

    // Create manager object
    auto manager = new RealEstateManager();

    // Create agent object
    auto agent = new RealEstateAgent("Soma", Date(12, 02, 2002), 2002, Date(02, 05, 2025));

    // Insert agent into the RealEstateManager
    manager->insert_agent(agent);

    // Set the agent id of each Property to the agent that was created.
    apt->set_agent_id(agent->get_employee_id());
    house->set_agent_id(agent->get_employee_id());
    land->set_agent_id(agent->get_employee_id());

    // Insert all the properties in the RealEstateManager
    manager->insert_property(apt);
    manager->insert_property(house);
    manager->insert_property(land);

    // Print information of all land properties (only one was created)
    manager->print_all_lands();

    // Sell house
    manager->sold_property(apt, 10000, Date(02, 12, 2002));

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