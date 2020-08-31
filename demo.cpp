#include "infinity.h"
#include <thread>
#include <chrono>

using namespace std;

/*
 * This is a driver file that demonstrates how to call each of the
 * library methods
 */

int main(int argc, char** argv) {
	// Print
	infinite inf1(39);
	inf1.print();

	// sleep for 1 second between random number generation
	this_thread::sleep_for(chrono::seconds(1));

	Infinite inf2(19);
	inf2.print();

	// Subtract
	inf1.subtract(inf2);

	// Addition
	
	// Subtraction

	// Multiplication

	// Division

	return 0;
}
