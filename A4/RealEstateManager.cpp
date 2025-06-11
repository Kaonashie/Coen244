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
}

// Management functions
void RealEstateManager::insert_agent(RealEstateAgent *agent) {
	for (int i = 0; i < 30; i++) {
		if (agents[i] == nullptr) {
			agents[i] = agent;
			break;
		}
	}
}

void RealEstateManager::insert_property(Property *property) {
	for (int i = 0; i < 1000; i++) {
		if (properties_for_sale[i] == nullptr) {
			properties_for_sale[i] = property;
			break;
		}
	}

	for (int k = 0; k < 30; k++) {
		if (agents[k]->get_employee_id() == property->get_agent_id()) {
			agents[k]->add_property(property);
			break;
		}
	}
}

void RealEstateManager::sold_house(Property *property, int price, Date date_of_sale) {
	if (property == nullptr) {
		std::cout << "Cannot process property\n";
		return;
	}
	for (int i = 0; i < 1000; i++) {
		if (properties_for_sale[i]->get_unique_id() == property->get_unique_id()) {
			properties_for_sale[i] = nullptr;
			for (int k = 0; k < 30; k++) {
				if (agents[k]->get_employee_id() == property->get_agent_id()) {
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
	for (int i = 0; i < 1000; i++) {
		if (properties_for_sale[i] != nullptr && properties_for_sale[i]->get_unique_id() == id) {
			std::cout << "Address: "<< properties_for_sale[i]->get_address() << "\n"
			<< "Sale Price: "<< properties_for_sale[i]->get_sale_price() << "\n"
			<< "Listing date: " <<properties_for_sale[i]->get_listing_date() << "\n"
			<< "Unique id: " << properties_for_sale[i]->get_unique_id() << "\n";
		}
	}
}

void RealEstateManager::print_agent_properties(int agent_id) const {
	for (int i = 0; i < 30; i++) {
		if (properties_for_sale[i]->get_agent_id() == agent_id) {
			print_property_info(properties_for_sale[i]->get_unique_id());
		}
	}
}

void RealEstateManager::print_all_lands() const {
	for (int i = 0; i < 1000; i++) {
		if (properties_for_sale[i] != nullptr) {
			if (dynamic_cast<LandSale*>(properties_for_sale[i])) {
				print_property_info(properties_for_sale[i]->get_unique_id());
			}
		}
	}
}
