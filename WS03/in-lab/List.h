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
using namespace std;

namespace sdds {
	template<typename T, int N>
	class List {
		T m_array[N];
		size_t m_numOfElements {0u};
	public:
		size_t size() const {
			return m_numOfElements;
		}

		const T& operator[](size_t i) const {
			return m_array[i];
		}

		void operator+=(const T& t) {
			if (N > size()) {
				m_array[m_numOfElements] = t;
				m_numOfElements++;
			}
		}
	};

}
