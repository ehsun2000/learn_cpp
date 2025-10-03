// The following program is supposed to add two numbers, but doesn’t work correctly.
// Use the integrated debugger to step through this program and watch the value of x. Based on the information you learn, fix the following program:

// input 2 and 3 then show The sum is: 3 is incorrect

// because x init 0, first readNumber(x) return 2 but not assign to x
// then second readNumber(x) return 3 but not assign to x
// x = 0 + 3 = 3

// so we should assign the return value of readNumber(x) to x


#include <iostream>

int readNumber(int x)
{
	std::cout << "Please enter a number: ";
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << '\n';
}

int main()
{
	int x {};
	x = readNumber(x) + readNumber(x);
	writeAnswer(x);

	return 0;
}