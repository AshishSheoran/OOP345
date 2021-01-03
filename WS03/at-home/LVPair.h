// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: Sept 28, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#include<iostream>
#include<string>

namespace sdds {
    template<typename L , typename V>
    class LVPair {
        L m_label;
        V m_value;
    public:
        LVPair() {
            this->m_label = "";
        }
        
        LVPair(const L& aa, const V& bb) {
            this->m_label = aa;
            this->m_value = bb;
        }
        
        const L& key() const {
            return this->m_label;
        }
        
        const V& value() const {
            return this->m_value;
        }
        
        virtual display(std::ostream& os) const {
            os << this->key() << " : " << this->value();
        }
    };

    template<typename L , typename V >
    std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
        pair.display(os);
        return os;
    }

    template<typename L, typename V>
    class SummableLVPair : public LVPair<L, V> {
        static V innitialValue;
        static size_t minWidth;
    public:
        static const V& getInitialValue() {
            return innitialValue;
        }
        
        SummableLVPair () {
            
        }
        
        SummableLVPair(const L& lbl, const V& val) : LVPair<L, V>(lbl, val) {
            if(lbl.size() > minWidth) {
                minWidth = lbl.size();
            }
        }
        
        V sum(const L& lbl, const V& val) const {
            if(this->key() == lbl) {
                return val + this->value();
            }
            return val;
        }
        
        void display(std::ostream& os) const {
            os << std::left << setw(this->minWidth);
            LVPair<L, V>::display(os);
            os << std::right;
        }
        
    };


    template<typename L, typename V>
    size_t SummableLVPair<L, V>::minWidth = 0;

    template<>
    std::string SummableLVPair<std::string, std::string>::initialValue = "";

    template<>
    int SummableLVPair<std::string, int>::initialValue = 0;

    template<>
    std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& val) const {
        if(key() == label) {
            if(val == "") {
                return this->value();
            }
            return val + "," + this->value();
        }
        return val;
    }



}
