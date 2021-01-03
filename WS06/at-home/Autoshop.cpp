// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Autoshop.h"

namespace sdds
{
    
    Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
    {
        m_vehicles.push_back(theVehicle);
        return *this;
    }

    
    void Autoshop::display(std::ostream& os) const {
        os << "--------------------------------\n";
        os << "| Cars in the autoshop!        |\n";
        os << "--------------------------------\n";
        for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
            (*i)->display(os);
            os << std::endl;
        }
        os << "--------------------------------\n";
    }

    
    Autoshop::~Autoshop()
    {
        std::vector<Vehicle*>::iterator i;
        for (i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
            delete (*i);
        }
        m_vehicles.clear();
    }
}
