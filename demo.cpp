#include "infinity.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

/*
 * This is a driver file that demonstrates how to call each of the
 * library methods
 */

int main(int argc, char** argv) {
	infinite inf1("0b1000");

	inf1.print();

	// sleep for 1 second between random number generation
	this_thread::sleep_for(chrono::seconds(1));

	infinite inf2("0b101");

	inf2.print();

	// Subtraction
	infinite inf3 = inf1.subtract(inf2);

	vector<bool> a;

	a.push_back(true);
	a.push_back(false);
	a.push_back(false);
	a.push_back(true);
	a.push_back(true);
	a.push_back(true);

	bool x = true;

	vector<bool> b = vector<bool>(a.end() - 3, a.end());

	//b.insert(b.begin(), false);

	auto print = [](bool item) { cout << item; };

	for (auto i = 0; i < b.size(); i++) {
		cout << b[i];
	}

	cout << endl;

	for_each(a.begin(), a.end(), print);

	cout << endl;

	cout << "inf5 init" << endl;

	auto inf5 = infinite("0b1000000000111");

	cout << "inf6 init" << endl;

	auto inf6 = infinite("0b101");

	cout << "calling division" << endl;

	auto inf7 = inf5.divide(inf6);

	inf5.print_raw();

	cout << " / ";

	inf6.print_raw();

	cout << " = ";

	get<0>(inf7).print_raw();

	cout << " rem ";

	get<1>(inf7).print_raw();

	cout << endl;

	// Division
	//tuple<infinite, infinite> inf4 = inf1.divide(inf2);

/*
	// initialize a random infinite with "length" digits
infinite::infinite(int length) {
	srand(time(NULL));

	for(int i = 0; i < length - 1; i++) {
		this->digits.push_back(rand() % 2);
	}

	// ensure the last digit (highest position) is non-empty
	this->digits.push_back(1);
	this->positive = true;
}*/

	// test with bash + python (aka python3) with this command:
	// x=0; while [ $x -le 100 ]; do python -c "$(./demo)" $((x++)); done
	cout << "print('";
	inf1.print_raw();
	cout << " - ";
	inf2.print_raw();
	cout << " = ";
	inf3.print_raw();
	cout << "');";
	cout << "print(bin(0b";
	inf1.print_raw();
	cout << " - 0b";
	inf2.print_raw();
	cout << ") == '0b";
	inf3.print_raw();
	cout << "')\n";

	// Addition
	
	// Subtraction

	// Multiplication

	// Division

	return 0;
}
