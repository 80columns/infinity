#ifndef INFINITY_H
#define INFINITY_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class infinite {
	public:
		infinite();
		infinite(int _length);
		//infinite(const infinite& _inf);
		infinite subtract(infinite _inf);
		void print();

	private:
		vector<bool> digits;
		bool positive;
};
#endif
