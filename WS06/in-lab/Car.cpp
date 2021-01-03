// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: November 4, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Car.h"

namespace sdds
{
   
    void Car::trim(std::string& str) const {
        size_t i = 0u;
        
        for (i = 0u; i < str.length() && str[i] == ' '; ++i);
        
        str = str.substr(i);
        for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
        str = str.substr(0, i);
    }


    
    Car::Car(std::istream& is)
    {
        std::getline(is, m_maker, ',');
        trim(m_maker);

        std::string tempCondition;
        std::getline(is, tempCondition, ',');
        trim(tempCondition);
        if (tempCondition == "n") {
            m_condition = "new";
        }
        else if (tempCondition == "u") {
            m_condition = "used";
        }
        else if (tempCondition == "b") {
            m_condition = "broken";
        }
        else {
            m_condition = "";
        }

        std::string tempSpeed;
        std::getline(is, tempSpeed);
        trim(tempSpeed);
        try {
            m_topSpeed = std::stoi(tempSpeed);
        }
        catch (...) {
            m_topSpeed = 0u;
        }

    }
    
    
    std::string Car::condition() const
    {
        return m_condition;
    }

    
    double Car::topSpeed() const
    {
        return static_cast<double>(m_topSpeed);
    }

    
    void Car::display(std::ostream& os) const
    {
        os << "| " << std::setw(10) << std::right << m_maker << " | "
            << std::setw(6) << std::left << m_condition << " | "
            << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed()
            << " |" << std::endl;
    }
}
