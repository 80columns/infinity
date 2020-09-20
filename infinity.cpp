#include "infinity.h"

using namespace std;

// initialize an empty infinite. default value is 0
infinite::infinite() {
	this->digits.push_back(0);
	this->positive = true;
}

// initialize an infinite based on a vector of bits
// this method assumes the input vector bits are already ordered from lowest place to highest place
infinite::infinite(vector<bool> _digits) {
	this->digits = _digits;
	this->positive = true;
}

// initialize an infinite based on the string representation of a number in binary, hexadecimal, or decimal
infinite::infinite(string _digits) {
	if (_digits.empty()) {
		// if the string is empty, then initialize the infinite to 0
		this->digits.push_back(0);
		this->positive = true;
	}
	else {
		size_t start_index = 0;

		// check whether the number should be negative or positive based on the minus sign at the beginning of the string
		if (_digits.at(0) == '-') {
			this->positive = false;
			start_index = 1;
		}
		else {
			this->positive = true;
		}

		if (
			_digits.size() >= start_index + 2
		 && _digits.substr(start_index, 2) == "0b"
		) {
			// process the number as binary
			start_index += 2;

			// ignore leading 0s in the input string
			while (
				start_index < _digits.size() &&
				_digits.at(start_index) == '0'
			) {
				start_index++;
			}

			// if the string consists entirely of 0s, initialize the infinite to 0
			if (start_index == _digits.size() - 1) {
				this->digits.push_back(0);
			}
			else {
				// store the binary number backwards, with the lowest-place digit at index 0
				for (int i = _digits.size() - 1; i >= start_index; i--) {
					if (_digits.at(i) == '1') {
						this->digits.push_back(1);
					}
					else if (_digits.at(i) == '0') {
						this->digits.push_back(0);
					}
					else {
						// throw an exception if the string contains any characters other than 1s or 0s
						throw _digits;
					}
				}
			}
		}
		else if (
			_digits.size() >= start_index + 2
		 && _digits.substr(start_index, 2) == "0x"
		) {
			// process the number as hexadecimal
			start_index += 2;

			// ignore leading 0s in the input string
			while (
				start_index < _digits.size() &&
				_digits.at(start_index) == '0'
			) {
				start_index++;
			}

			// convert hexadecimal number to binary

		}
		else {
			// process the number as decimal

			// ignore leading 0s in the input string
			while (
				start_index < _digits.size() &&
				_digits.at(start_index) == '0'
			) {
				start_index++;
			}

			// convert decimal number to binary

		}
	}
}

void infinite::print() {
	cout << "forward:" << endl;

	if (this->positive == false) {
		cout << "-";
	}

	for (auto i = 0; i < this->digits.size(); i++) {
		cout << this->digits.at(i);
	}

	cout << endl;

	cout << "backward:" << endl;

	if (this->positive == false) {
		cout << "-";
	}

	for (int j = this->digits.size() - 1; j >= 0; j--) {
		cout << this->digits.at(j);
	}

	//cout << this->digits[0];

	cout << endl;

	cout << "default:" << endl;

	if (this->positive == false) {
		cout << "-";
	}

	// Print number as binary
	
	// set up print lambda
	auto print = [](bool item) { cout << item; };

	// iterate over vector, calling print method on each item
	for_each(this->digits.rbegin(), this->digits.rend(), print);

	cout << endl;

	//cout << "\n";

	// Print number as decimal
	//
	
}

void infinite::print_raw() {
	if (this->positive == false) {
		cout << "-";
	}

	auto print = [](bool item) { cout << item; };

	for_each(this->digits.rbegin(), this->digits.rend(), print);
}

// compare two infinites to determine which is larger
// return 1 if this is larger
// return 0 if this and _inf are equal
// return -1 if _inf is larger
int infinite::compare(infinite _inf) {
	int result = 0;

	// try to determine size based on # of digits
	if (this->digits.size() > _inf.digits.size()) {
		result = 1;
	}
	else if (this->digits.size() < _inf.digits.size()) {
		result = -1;
	}
	else {
		size_t i = this->digits.size() - 1;

		// if all of the digits are found to be equal in the for loop, result will remain 0
		while (i > 0) {
			if (this->digits.at(i) != _inf.digits.at(i)) {
				result = (this->digits.at(i) == 1) ? 1 : -1;
				break;
			}

			i--;
		}

		// size_t can't be set to -1 above, so comparing i >= 0 in the loop will crash
		// do an extra check for index 0 here instead if result hasn't already been set either way
		if (
			result == 0
		 && this->digits.at(0) != _inf.digits.at(0)
		) {
			result = (this->digits.at(0) == 1) ? 1 : -1;
		}
	}

	return result;
}

// subtract _inf from the current inifinite
// return a new infinite containing the result of the subtraction
infinite infinite::subtract(infinite _inf) {
	infinite result;
	infinite lower;

	int compare_result = this->compare(_inf);

	// this and _inf are the same number, so the result is 0
	if (compare_result == 0) {
		// if the two numbers are the same, the result is 0
		result = infinite();
	}
	else {
		// this is larger, subtract _inf from this
		if (compare_result == 1) {
			result = infinite(*this);
			lower = infinite(_inf);
		}
		// _inf is larger, subtract this from _inf and set result to negative
		else if (compare_result == -1) {
			result = infinite(_inf);
			result.positive = false;

			lower = infinite(*this);
		}

		for (size_t i = 0; i < lower.digits.size(); i++) {
			// 0 - 0 handled without calculation
		
			// 1 - 0 handled without calculation

			// 1 - 1 results in 0
			if (
				result.digits.at(i) == 1
				&& lower.digits.at(i) == 1
			) {
				result.digits[i] = 0;
			}
			// 0 - 1 results in borrowing from higher-place digits
			else if (
				result.digits.at(i) == 0
				&& lower.digits.at(i) == 1
			) {
				size_t j = i;

				// traverse the number to find the first higher occurrence of a 1
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

		// remove any leading 0s from result (index 0 can't be a 0 as this & _inf failed the equality test to get here)
		// these are at the end of the vector as the highest-position digits are at the end of the vector
		size_t i = result.digits.size() - 1;

		while(result.digits.at(i--) == 0) {
			result.digits.pop_back();
		}
	}

	return result;
}

// divide the current infinite by _divisor
// return a tuple of 2 infinites containing the (1st item) quotient & (2nd item) remainder of the division operation
tuple<infinite, infinite> infinite::divide(infinite _divisor) {
	// quotient & remainder are both initialized to 0 by the default constructor
	infinite quotient;
	infinite remainder;
	
	// if _divisor is equal to the current infinite, no need to calculate anything as quotient & remainder are initialized to 0
	int compare_result = this->compare(_divisor);

	// if _divisor is greater than the current infinite, quotient is 0 and remainder is _divisor - this
	if (compare_result == -1) {
		remainder = _divisor.subtract(*this);
	}
	// if _divisor is less than the current infinite, calculate the quotient & remainder using the "shift and subtract" algorithm
	// see https://courses.cs.vt.edu/~cs1104/BuildingBlocks/divide.030.html for a straightforward explanation
	else if (compare_result == 1) {
		size_t dividend_index = _divisor.digits.size();

		quotient.digits.clear();
		remainder.digits.assign(this->digits.end() - dividend_index, this->digits.end());

		while (dividend_index < this->digits.size()) {
		 	// if the remainder is greater than or equal to the divisor then append a 1 to the quotient and subtract the divisor from the remainder
		 	if (remainder.compare(_divisor) >= 0) {
		 		quotient.digits.push_back(1);
		 		remainder = remainder.subtract(_divisor);
		 	}
		 	else {
		 		quotient.digits.push_back(0);
		 	}

			remainder.digits.insert(remainder.digits.begin(), this->digits.at(this->digits.size() - 1 - dividend_index));

			// remove any leading 0s from remainder
			while (
				remainder.digits.size() > 0
			 && remainder.digits.at(remainder.digits.size() - 1) == 0
			) {
				remainder.digits.pop_back();
			}

		 	dividend_index++;
		}

		if (remainder.compare(_divisor) >= 0) {
			quotient.digits.push_back(1);
			remainder = remainder.subtract(_divisor);
		}
		else {
			quotient.digits.push_back(0);
		}

		// reverse the digits of the quotient
		reverse(quotient.digits.begin(), quotient.digits.end());

		// remove any leading 0s from quotient
		size_t i = quotient.digits.size() - 1;

		while(quotient.digits.at(i--) == 0) {
			quotient.digits.pop_back();
		}
	}

	return { quotient, remainder };
}