//
// Created by soma on 02/06/25.
//

#ifndef HouseSale_H
#define HouseSale_H
#include "Property.h"

class HouseSale : public Property {
   private:
    std::string house_type;
    int year_built{}, no_rooms{}, sale_price{};

   public:
    // Constructors
    HouseSale(std::string address = "", Customer customer = Customer(), int agent_id = 0, Date listing_date = Date(),
	      Date sell_date = Date(), int sold_price = 0, std::string house_type = "", int year_built = 0,
	      int no_rooms = 0, int sale_price = 0);

    // Destructor
    ~HouseSale();

    // Getter methods
    std::string get_house_type() const;
    int get_year_built() const;
    int get_no_rooms() const;
    virtual int get_sale_price() const;

    // Setter methods
    HouseSale* set_year_built(int n_year);
    HouseSale* set_no_rooms(int n_rooms);
    HouseSale* set_sale_price(int sale_price);
    HouseSale* set_house_type(std::string type);

    // Print function
    virtual void print_info() const;
};

#endif	// HouseSale_H
