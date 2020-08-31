#include "infinity.h"

using namespace std;

infinite::infinite() {
	this->digits.push_back(0);
	this->positive = true;
}

infinite::infinite(int length) {
	this->digits.push_back(1);

	srand(time(NULL));

	for(int i = 0; i < length; i++) {
		this->digits.push_back(rand() % 2);
	}

	this->positive = true;
}

void infinite::print() {
	// Print number as binary
	//
	// set up print method
	// iterate over vector, calling print method on each item
	
	if (this->positive == false) {
		cout << "-";
	}
	
	auto print = [](bool item) { cout << item; };

	for_each(this->digits.begin(), this->digits.end(), print);

	cout << "\n";

	// Print number as decimal
	//
	
}

void infinite::subtract(infinite _inf) {
	// For now, assume that this->digits is larger than _inf.digits

	cout << "this vector size: " << this->digits.size() << "\n";
	cout << "_inf vector size: " << _inf.digits.size() << "\n";

	for (int i = this->digits.size() - 1, j = _inf.digits.size() - 1; i >= 0, j >= 0; i--, j--) {
		
	}
}
