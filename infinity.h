#ifndef INFINITY_H
#define INFINITY_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class infinite {
	public:
		infinite();
		infinite(int length);
		void subtract(infinite inf);
		void print();

		vector<bool> digits;

	private:
		bool positive;
};
#endif
