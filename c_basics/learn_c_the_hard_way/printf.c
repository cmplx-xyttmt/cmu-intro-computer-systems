#include <stdio.h>

int main() {
	int age = 10;
	int height = 72;

	printf("I am %d years old. \n", age);
	printf("I am %d inches tall.\n", height);

	double exp = 1e19;
	float norm = 8.9;
	printf("As an exponent: exp = %e and norm = %e\n", exp, norm);
	printf("As normal floats: exp = %f and norm = %f\n", exp, norm);
	printf("Choose: exp = %g and norm = %g\n", exp, norm);

	// Playing with escape sequences
	// A null character \0 will terminate the string
	printf("This will be followed by a tab \t this will be followed by a vertical tab \v backspace\b \"C is fun\"\n");
}
