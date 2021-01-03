// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iomanip>
#include "Vehicle.h"
#include <sstream>

namespace sdds
{
    class Car : public Vehicle
    {
    private:
        std::string m_maker = "";
        std::string m_condition = "";
        size_t m_topSpeed = 0u;
    public:
        void trim(std::string& str) const;
        Car(std::istream& is);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream& os) const;
    };
}
#endif // !SDDS_CAR_H
