//
// Created by soma on 02/06/25.
//

#ifndef REALESTATEMANAGER_H
#define REALESTATEMANAGER_H
#include "LandSale.h"
#include <fstream>
#include "RealEstateAgent.h"

class RealEstateManager {
   private:
    RealEstateAgent* agents[30];
    Property* properties_for_sale[1000];
    Property* properties_sold[500];

   public:
    // Constructors
    RealEstateManager();

    // Destructor
    ~RealEstateManager();

    // Management functions
    void insert_agent(RealEstateAgent* agent);
    void insert_property(Property* property);
    void sold_property(Property* property, int price, Date date_of_sale);

    // Utility functions (array manip and io)
    bool remove_property(Date currentDate);
    bool savePerson(std::string personFile, Person * person);
    void searchPerson(std::string personFile, std::string className, std::string personName);

    // Print functions
    void print_property_info(int id) const;
    void print_agent_properties(int agent_id) const;
    void print_all_lands() const;
};

#endif	// REALESTATEMANAGER_H
