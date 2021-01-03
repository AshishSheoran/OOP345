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
            m_label = "";
        }
		LVPair(const L& aa, const V& bb) {
            m_label = aa;
            m_value = bb;
        }
        const L& key() const {
            return m_label;
        }
        const V& value() const {
            return m_value;
        }
		void display(std::ostream& os) const {

			os << m_label << " : " << m_value << std::endl;
		
		}
	};

	template<typename L , typename V >
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}
}




