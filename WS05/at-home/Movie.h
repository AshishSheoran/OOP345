// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: October 18, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>
#include <iomanip>
#include <string>

namespace sdds
{
    class Movie
    {
    private:
        std::string m_title = "";
        std::string m_description = "";
        size_t m_year = 0u;

        void trim(std::string& str) const; 
    public:
        Movie() {};
        Movie(const std::string& strMovie);
        const std::string& title() const { return m_title; };

        
        template<typename T>
        void fixSpelling(T spellChecker) {
            spellChecker(m_title);
            spellChecker(m_description);
        }
        friend std::ostream& operator<<(std::ostream& os, const Movie& m);
    };
}

#endif // !SDDS_MOVIE_H
