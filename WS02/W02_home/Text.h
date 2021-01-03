// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: Sept 24, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef Text_h
#define Text_h

#include <iostream>
#include <cstring>
#include <fstream>
namespace sdds {
    
    class Text{
        std::string* textLine;
        int num;
        static unsigned numText;

    public:
        Text();
        Text(const std::string&);
        Text(const Text&);
        Text(Text&&);
        Text&operator=(const Text&);
        Text&operator=(Text&&);
        ~Text();
        size_t size()const;
    };
}

#endif /* Text_h */
