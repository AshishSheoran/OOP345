// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef Racecar_h
#define Racecar_h

#include <iostream>
#include "Car.h"

namespace sdds {

    class Racecar : public Car {
        
        double m_booster = 0.0;
    public:
        Racecar(std::istream& is);
        void display(std::ostream& out) const;
        double topSpeed() const;
    };

}

#endif /* Racecar_h */
