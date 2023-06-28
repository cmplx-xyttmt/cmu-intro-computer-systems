#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
	char * s = "mystring";
	printf("Length of the string is: %lu\n", strlen(s));
	printf("Size of the string is: %lu\n", sizeof(s));
}

