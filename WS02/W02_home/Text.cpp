// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: Sept 24, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include "Text.h"


//ofstream => 文件寫操作 內存寫入儲存設備
//ifstream => 文件讀操作 儲存設備讀取到內存中
//fstream  => 讀寫操作 對打開的文件可進行讀寫操作

namespace sdds {
    
    unsigned Text::numText = 0u;
    
    Text::Text(){
        numText++;
    }
    
// open() => void open(const char* filename, int mode, int access)
// filename => the file you wanna open
// mode => the method that you open the file
// access => the file's preperty
    

    Text::Text(const std::string& filename)
    {
        numText++;
        std::ifstream f(filename.c_str());
        num = 0u;
        textLine = nullptr;
        
        if (!f)
            return;
        do{
            char c = f.get();
            if (c == ' ')
                num++;
        }while (!f.eof()) ;
        
        
        f.seekg(std::ios::beg);
        textLine = new std::string[num];
        for (unsigned i = 0u; i < num; i++)
            std::getline(f, textLine[i], ' ');
    }

    Text::Text(const Text& text){
        numText++;
        *this = text;
    }
    
    Text::Text(Text&& text){
        numText++;
        *this = std::move(text);
    }
    
    Text& Text::operator=(const Text& text){
        if (this != &text && text.textLine != nullptr) {
            if (this->textLine != nullptr) {
                delete[] this-> textLine;
                this->textLine = nullptr;
                this->num = 0u;
            }
            this->textLine = new (std::nothrow) std::string[text.num];
            if (this->textLine != nullptr) {
                for (unsigned i = 0u; i < text.num; i++) {
                    this->textLine[i] = text.textLine[i];
                    this->num++;
                }
            }
        }
        return *this;
    }
    
    Text& Text::operator=(Text&& text){
        if (this != &text && text.textLine != nullptr) {
            if (this->textLine != nullptr) {
                delete[] textLine;
            }
            this->textLine = text.textLine;
            this->num = text.num;
            text.textLine = nullptr;
            text.num = 0u;
        }
        return *this;
    }
    
    Text::~Text(){
        if (this->textLine != nullptr) {
            delete[] this->textLine;
            numText--;
        }
    }
    
    size_t Text::size() const{
        return this->num;
    }
}
