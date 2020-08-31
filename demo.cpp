#include "infinity.h"
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

/*
 * This is a driver file that demonstrates how to call each of the
 * library methods
 */

int main(int argc, char** argv) {
	// Print
	infinite inf1(40);

	// sleep for 1 second between random number generation
	this_thread::sleep_for(chrono::seconds(1));

	infinite inf2(20);

	// Subtract
	infinite inf3 = inf1.subtract(inf2);

	// test with bash + python (aka python3) with this command:
	// x=0; while [ $x -le 100 ]; do python -c "$(./demo)" $((x++)); done
	cout << "print('";
	inf1.print();
	cout << " - ";
	inf2.print();
	cout << " = ";
	inf3.print();
	cout << "');";
	cout << "print(bin(0b";
	inf1.print();
	cout << " - 0b";
	inf2.print();
	cout << ") == '0b";
	inf3.print();
	cout << "')\n";

	// Addition
	
	// Subtraction

	// Multiplication

	// Division

	return 0;
}
