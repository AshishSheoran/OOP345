// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: November 4, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <sstream>
#include "Vehicle.h"
#include "Car.h"

namespace sdds
{
    Vehicle* createInstance(std::istream& in);
}

#endif // !SDDS_UTILITIES_H
