// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: Sept 21, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "Text.h"

namespace sdds {

int Text::counter = 0;

// Default Constructor
Text::Text()
    : words(nullptr)
{
}

// One Argument Constructor
Text::Text(const char* other) {
    std::string buffer;
    std::ifstream file;
    file.open(other);
    
    if(file.is_open()) {
        while(std::getline(file,buffer)){
            counter++;
        }
    }
    
    words = new std::string[counter];
    
    int i = 0;
    std::string line;
    
    while(std::getline(file,buffer)) {
        words[i] = line;
    }
}

// Copy Constructor
Text::Text(const Text& other) {
    *this = other;
}


// Copy Assignment Operator
Text& Text::operator=(const Text& other) {
    if (this != &other) {
        counter = other.counter;
        
        if (other.words != nullptr) {
            words = new std::string[counter];
            for (int i = 0; i < counter; i++) {
                words[i] = other.words[i];
            }
        }
    }
    return *this;
}
// default destructor
//
Text::~Text() {
    delete[] words;
    words = nullptr;
}
// function return the counter
//
size_t Text::size() const {
    return counter;
}

}
