// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: November 4, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include "Vehicle.h"

namespace sdds
{
    class Autoshop
    {
    private:
        std::vector<Vehicle*> m_vehicles;
    public:
        Autoshop& operator +=(Vehicle* theVehicle);
        void display(std::ostream& os) const;
        ~Autoshop();
    };
}
#endif // !SDDS_AUTOSHOP_H
