// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: Sept 21, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef Text_h
#define Text_h

#include<iostream>
#include<string>
#include<fstream>

namespace sdds {

    class Text {
        std::string* words;
        static int counter;
    public:
        Text();
        Text(const char*);
        Text(const Text&);
        Text& operator=(const Text&);
        ~Text();
        size_t size() const;
    };

}


#endif /* Text_h */
