#include "infinity.h"

using namespace std;

// initialize an empty infinite. default value is 0
infinite::infinite() {
	this->digits.push_back(0);
	this->positive = true;
}

// initialize a random infinite with "length" digits
infinite::infinite(int length) {
	srand(time(NULL));

	for(int i = 0; i < length - 1; i++) {
		this->digits.push_back(rand() % 2);
	}

	// ensure the last digit (highest position) is non-empty
	this->digits.push_back(1);
	this->positive = true;
}

void infinite::print() {
	// Print number as binary
	//
	// set up print method
	// iterate over vector, calling print method on each item
	
	//cout << "printing infinite\n";
	
	if (this->positive == false) {
		cout << "-";
	}
	
	auto print = [](bool item) { cout << item; };
	for_each(this->digits.rbegin(), this->digits.rend(), print);

	//cout << "\n";

	// Print number as decimal
	//
	
}

infinite infinite::subtract(infinite _inf) {
	// create a copy of the current infinite object to modify & return
	infinite result(*this);

	// For now, assume that this->digits is larger than _inf.digits
	for (int i = 0; i < _inf.digits.size(); i++) {
		// 0 - 0 handled without calculation
		// 1 - 0 handled without calculation

		// 1 - 1 results in 0
		if (
			result.digits.at(i) == 1
			&& _inf.digits.at(i) == 1
		) {
			//cout << "index " << i << ", 1 - 1 case\n";

			result.digits[i] = 0;
		}
		// 0 - 1 results in borrowing from higher-place digits
		else if (
			result.digits.at(i) == 0
			&& _inf.digits.at(i) == 1
		) {
			int j = i;

			//cout << "index " << i << ", 0 - 1 case\n";

			// look up the number to find the first higher occurrence of a 1
			while (result.digits.at(++j) == 0) { }

			// borrow from the index at j, which sets its place to 0
			result.digits[j] = 0;

			// cascade the borrow down the digits until reaching i
			while (--j > i) {
				result.digits[j] = 1;
			}

			// perform 10 - 1 now that 1 has been borrowed from a higher digit
			result.digits[i] = 1;
		}
	}

	return result;
}
