// Name: Ashish Sheoran
// Seneca Student ID: 162543177
// Seneca email: asheoran1@myseneca.ca
// Date of completion: Sept 28, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include<iostream>
#include <vector>
#include <string>
#include "LVPair.h"

namespace sdds {
    template<typename T, int N>
    class List {
        T m_array[N];
        size_t m_numOfElements {0u};
    public:
        size_t size() const {
            return this->m_numOfElements;
        }

        const T& operator[](size_t i) const {
            return m_array[i];
        }

        void operator+=(const T& t) {
            if (this->m_numOfElements < N) {
                array[m_numOfElements++] = t;
            }
        }
    };


    template<typename L, typename V, typename T, int N>
    class LVList : public List<T, N> {
    public:
        V accumulate(const L& label) const {
            V local = T::getInitialValue();
            for (size_t i = 0; i < this->size(); i++) {
                local = ((List<T, N>&)*this)[i].sum(label, local);
            }
            return local;
        }
    };

}

