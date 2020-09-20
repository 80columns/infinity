#ifndef INFINITY_H
#define INFINITY_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <algorithm>

using namespace std;

class infinite {
	public:
		infinite();
		infinite(string _digits);
		void print();
		void print_raw();
		int compare(infinite _inf);
		infinite subtract(infinite _inf);
		std::tuple<infinite, infinite> divide(infinite _inf);
		
	private:
		infinite(vector<bool> _digits);

		vector<bool> digits;
		bool positive;
};
#endif
