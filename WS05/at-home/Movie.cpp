// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: October 18, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Movie.h"

namespace sdds
{
    
    void Movie::trim(std::string& str) const {
        size_t i = 0u;
    
        for (i = 0u; i < str.length() && str[i] == ' '; ++i);

        
        str = str.substr(i);

        for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
        str = str.substr(0, i);
    }

    
    Movie::Movie(const std::string& strMovie) {
        size_t posS = 0;
        size_t posE = strMovie.find(',');
        
        this->trim(m_title = strMovie.substr(posS, posE));

       
        posS = posE + 1;
        posE = strMovie.find(',', posS);
        this->m_year = std::stoi(strMovie.substr(posS, posE - posS));

        posS = posE + 1;
        this->trim(m_description = strMovie.substr(posS));
    }

    
    std::ostream& operator<<(std::ostream& os, const Movie& m) {
        os << std::setw(40) << m.m_title << " | " << std::setw(4) << m.m_year << " | " << m.m_description << std::endl;
        return os;
    }

}
