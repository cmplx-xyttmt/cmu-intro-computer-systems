#include <stdio.h>


// Doing multiplication using repeated addition
unsigned int multiply(unsigned int x, unsigned int y) {
	if (x == 1) return y;
	else if (x > 1) return y + multiply(x - 1, y);

	return 0;
}

unsigned int factorial(unsigned int x) {
	if (x == 0) return 1;
	return x * factorial(x - 1);
}

int main() {
	printf("3 times 5 is %d\n", multiply(3, 5));
	printf("0! = %d, 1! = %d, 2! = %d, 5! = %d\n", factorial(0), factorial(1), factorial(2), factorial(5));
	printf("10! = %d\n", factorial(10));
	printf("20! = %d\n", factorial(20)); // overflow?
	return 0;
}

