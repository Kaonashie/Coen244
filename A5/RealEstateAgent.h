//
// Created by soma on 02/06/25.
//

#ifndef REALESTATEAGENT_H
#define REALESTATEAGENT_H
#include "Person.h"
#include "Property.h"

class RealEstateAgent : public Person {
   private:
    int employee_id;
    Date employment_date;
    Property* properties[20];

   public:
    // Constructors
    RealEstateAgent(std::string name = "", Date dob = Date(), int employee_id = 0, Date employment_date = Date());

    // Getter methods
    int get_employee_id() const;
    Date get_employment_date() const;

    // Setter methods
    void set_employee_id(const int employee_id);
    void set_employment_date(const Date& employment_date);
    bool add_property(Property* prop);
    bool remove_property(Property* prop);

    // Print function
    void print_info() const;

    // Destructor
    ~RealEstateAgent();
};

#endif	// REALESTATEAGENT_H
