// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
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
        
        
        template<typename T>
        void select(T test, std::list<const Vehicle*>& vehicles) {
            std::vector<Vehicle*>::iterator i;
            for(i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
                if(test(*i)) {
                    vehicles.push_back(*i);
                }
            }
        }
    };
}
#endif // !SDDS_AUTOSHOP_H
