// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: October 18, 2019
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>
#include <string>
#include <fstream>

namespace sdds
{
    class SpellChecker
    {
    private:
        std::string m_badWords[5];
        std::string m_goodWords[5];
        int cnt = 0;
    public:
        SpellChecker();
        SpellChecker(const char* filename);
        void operator()(std::string& text) const;
    };
}

#endif // !SDDS_SPELLCHECKER_H
