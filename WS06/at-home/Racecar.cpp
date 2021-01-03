// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Racecar.h"

namespace sdds {

    Racecar::Racecar(std::istream& is) : Car(is){
        size_t i = 0u;
        std::string token;
        std::getline(is, token);
        
        for(i = 0; i < token.size() && token[i] == ' '; i++);
        token = token.substr(i);
        
        for(i = token.size(); i > 0 && token[i-1] == ' '; i--);
        token = token.substr(0,i);
        
        m_booster = std::stod(token);
    }

    void Racecar::display(std::ostream& out) const {
        Car::display(out);
        out << "*";
    }

    double Racecar::topSpeed() const {
        return Car::topSpeed() * (1 + m_booster);
    }


}
