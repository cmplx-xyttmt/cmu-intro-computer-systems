#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * name;
    int age;
} person;

int main() {
    // Sizes of some types in bytes
    person p;
    char c;
    printf("Size of a char: %lu\n", sizeof(c));
    printf("Size of name string: %lu\n", sizeof(p.name)); // p.name is a pointer, which is an unsigned long, hence the 8 bytes length
    printf("Size of age int: %lu\n", sizeof(p.age));
    printf("Size of person struct in bytes: %lu\n", sizeof(person));
    p.name = "Isaac Owomugisha";
    printf("Size of name after assignment: %lu\n", sizeof(p.name)); // Size of name doesn't change since it's a pointer.

    // Allocate memory to hold a person
    person * myperson = (person *) malloc(sizeof(person));
    myperson->age = 78;
    myperson->name = "Grand";
    printf("%s is %d years old\n", myperson->name, myperson->age);
    free(myperson); // Free the memory.

    return 0;
}
