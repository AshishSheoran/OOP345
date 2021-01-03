// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: November 4, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Utilities.h"

namespace sdds
{
   
    Vehicle* createInstance(std::istream& in)
    {
        std::string line;
        char type = '\0';
        char delim = '\0';
        std::getline(in, line);
        std::stringstream ss(line);
        ss >> type >> delim;

        if (ss) {
            switch (type)
            {
            case 'c':
            case 'C':
                return new Car(ss);
                break;
            default:
                return nullptr;
                break;
            }
        }
        return nullptr;
    }
}
