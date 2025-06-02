//
// Created by soma on 02/06/25.
//

#include "RealEstateManager.h"
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
}
void RealEstateManager::sold_house(Property *property, int price, Date date_of_sale) {

}
void RealEstateManager::print_property_info(int id) const {}
void RealEstateManager::print_agent_properties(int agent_id) const {}
void RealEstateManager::print_all_properties() const {}
