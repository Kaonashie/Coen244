//
// Created by soma on 02/06/25.
//

#include "RealEstateManager.h"

// Constructors
RealEstateManager::RealEstateManager() {
    for (int i = 0; i < 30; i++) {
	agents[i] = nullptr;
    }

    for (int i = 0; i < 1000; i++) {
	properties_for_sale[i] = nullptr;
    }

    for (int i = 0; i < 500; i++) {
	properties_sold[i] = nullptr;
    }
}

// Destructor
RealEstateManager::~RealEstateManager() {
    for (int i = 0; i < 30; i++) {
	if (agents[i] != nullptr) {
	    delete agents[i];
	    agents[i] = nullptr;
	}
    }

    for (int i = 0; i < 1000; i++) {
	if (properties_for_sale[i] != nullptr) {
	    delete properties_for_sale[i];
	    properties_for_sale[i] = nullptr;
	}
    }

    for (int i = 0; i < 500; i++) {
	if (properties_sold[i] != nullptr) {
	    delete properties_sold[i];
	    properties_sold[i] = nullptr;
	}
    }
    std::cout << "Manager object successfully destroyed.\n";
}

// Management functions
void RealEstateManager::insert_agent(RealEstateAgent *agent) {
    if (agent == nullptr) {
	return;
    }
    for (int i = 0; i < 30; i++) {
	if (agents[i] == nullptr) {
	    agents[i] = agent;
	    break;
	}
    }
}

// Insert property in array of properties for sale and adds the property to the agent's properties as well.
void RealEstateManager::insert_property(Property *property) {
    if (property == nullptr) {
	return;
    }
    for (int i = 0; i < 1000; i++) {
	if (properties_for_sale[i] == nullptr) {
	    properties_for_sale[i] = property;
	    break;
	}
    }

    for (int k = 0; k < 30; k++) {
	if (agents[k] != nullptr && agents[k]->get_employee_id() == property->get_agent_id()) {
	    agents[k]->add_property(property);
	    break;
	}
    }
}

// Removes property from agent's property list, removes property from properties_for_sale array, adds property to
// properties_sold array. Updates the sell date and sold price of the property.
void RealEstateManager::sold_property(Property *property, int price, Date date_of_sale) {
    if (property == nullptr) {
	std::cout << "Cannot process property\n";
	return;
    }
    for (int i = 0; i < 1000; i++) {
	if (properties_for_sale[i] != nullptr && properties_for_sale[i]->get_unique_id() == property->get_unique_id()) {
	    properties_for_sale[i] = nullptr;
	    for (int k = 0; k < 30; k++) {
		if (agents[k] != nullptr && agents[k]->get_employee_id() == property->get_agent_id()) {
		    agents[k]->remove_property(property);
		    break;
		}
	    }
	    for (int j = 0; j < 500; j++) {
		if (properties_sold[j] == nullptr) {
		    properties_sold[j] = property;
		    properties_sold[j]->set_sold_price(price);
		    properties_sold[j]->set_sell_date(date_of_sale);
		    break;
		}
	    }
	    break;
	}
    }
}

// Print functions
void RealEstateManager::print_property_info(int id) const {
    // Verify if the property exists in the for sale or the sold arrays.
    std::cout << "Printing property information \n\n";
    for (int i = 0; i < 1000; i++) {
	if (properties_for_sale[i] != nullptr && properties_for_sale[i]->get_unique_id() == id) {
	    properties_for_sale[i]->print_info();
	    return;
	}
    }
    for (int i = 0; i < 500; i++) {
	if (properties_sold[i] != nullptr && properties_sold[i]->get_unique_id() == id) {
	    properties_sold[i]->print_info();
	    return;
	}
    }
}

// Prints the information of all the properties an agent is selling.
void RealEstateManager::print_agent_properties(int agent_id) const {
    for (int i = 0; i < 1000; i++) {
	if (properties_for_sale[i] != nullptr && properties_for_sale[i]->get_agent_id() == agent_id) {
	    properties_for_sale[i]->print_info();
	}
    }
}

// Removes a property if the current date is greater than 3 months more than the listing date
bool RealEstateManager::remove_property(Date currentDate) {
    for (int i = 0; i < 1000; i++) {
	if (properties_for_sale[i] != nullptr) {

	    // Lastest date that the property can be listed for.
	    Date latest_date = properties_for_sale[i]->get_listing_date() + 3;
	    if (currentDate > latest_date) {
		for (int k = 0; k < 30; k++) {
		    if (agents[k] != nullptr &&
			agents[k]->get_employee_id() == properties_for_sale[i]->get_agent_id()) {
			agents[k]->remove_property(properties_for_sale[i]);
		    }
		}
		delete properties_for_sale[i];
		properties_for_sale[i] == nullptr;
		return true;
	    }
	}
    }
    return false;
}

// Save a person with their information if they don't already exist in the file
bool RealEstateManager::savePerson(std::string personFile, Person *person) {
    auto inFile = std::ifstream(personFile, std::ios::in);

    std::string name;
    auto customer = dynamic_cast<Customer*>(person);
    auto realEstateAgent = dynamic_cast<RealEstateAgent*>(person);
    if (customer) {
        name = customer->get_name();
    } else if (realEstateAgent) {
        name = realEstateAgent->get_name();
    }

    std::string in, name_in_file;

    // Verify if the person exists in the file by looking at their name.
    while (inFile >> name_in_file) {
        if (name_in_file == name) {
            std::cout << name_in_file << " is already stored in the file\n";
            inFile.close();
            return false;
        }
    }

    inFile.close();
    auto outFile = std::ofstream(personFile, std::ios::app);

    if (customer) {
        outFile << "Customer " << person->get_name() << " " << person->get_date_of_birth().get_day() << " "
        	<< person->get_date_of_birth().get_month() << " " << person->get_date_of_birth().get_year() << " "
        	<< dynamic_cast<Customer *>(person)->get_social_insurance_number() << std::endl;
        outFile.close();
        std::cout << "Stored " << name << "\n";
    } else if (realEstateAgent) {
        outFile << "RealEstateAgent " << person->get_name() << " " << person->get_date_of_birth().get_day() << " "
        	<< person->get_date_of_birth().get_month() << " " << person->get_date_of_birth().get_year() << " "
        	<< realEstateAgent->get_employee_id() << " " << realEstateAgent->get_employment_date().get_day() << " "
        	<< realEstateAgent->get_employment_date().get_month() << " " << realEstateAgent->get_employment_date().get_year()
        	<< std::endl;
        std::cout << "Stored " << name << "\n";
        outFile.close();
    }
    return true;
}

void RealEstateManager::searchPerson(std::string personFile, std::string className, std::string personName) {
    auto inFile = std::ifstream(personFile, std::ios::in);
    // Verify if the person exists in the file by looking at their name.
    std::string cur_name, class_name;
    while (inFile >> class_name >> cur_name) {
        if (personName == cur_name && class_name == className) {
            std::cout << "\nFound " << cur_name << std::endl;;
            if (class_name == "Customer") {
                std::string sin;
                int day, month, year;
                inFile >> day >> month >> year >> sin;
                auto customer = new Customer(cur_name, Date(month, day, year), sin);
                std::cout << *customer << std::endl;
            } else if (class_name == "RealEstateAgent") {
                int employee_id;
                int day, eday, month, emonth, year, eyear;
                inFile >> day >> month >> year >> employee_id >> eday >> emonth >> eyear;
                auto agent = new RealEstateAgent(cur_name, Date(month, day, year), employee_id, Date(emonth, eday, eyear));
                std::cout << *agent << std::endl;
            }
            inFile.close();
        }
    }
}

// Prints the information of all the land type properties.
void RealEstateManager::print_all_lands() const {
    for (int i = 0; i < 1000; i++) {
	if (properties_for_sale[i] != nullptr) {
	    if (dynamic_cast<LandSale *>(properties_for_sale[i])) {
		print_property_info(properties_for_sale[i]->get_unique_id());
	    }
	}
    }
}
