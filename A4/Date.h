//
// Created by soma on 20/05/25.
//

#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date {
   private:
    int month, day, year;

   public:
    // Constructors
    Date();
    Date(int m, int d, int y);

    // Getter methods
    int get_month() const;
    int get_day() const;
    int get_year() const;

    // Setter methods
    void set_month(int m);
    void set_day(int d);
    void set_year(int y);

    // Print function
    void print_info() const;

    // Operator overload
    friend std::ostream &operator<<(std::ostream &os, const Date &dt);

    // Destructor
    ~Date();
};

#endif	// DATE_H
