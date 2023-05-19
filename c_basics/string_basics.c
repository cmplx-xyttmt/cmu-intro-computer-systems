#include <stdio.h>
#include <string.h>

int main() {
    char * name = "Isaac Owomugisha"; // Read only
    char mutable_name[] = "Isaac Owomugisha"; // Mutable string
    mutable_name[2] = 'b';

    printf("My name is %s and not %s\n", name, mutable_name);
    printf("The length of the name string is %lu\n", strlen(name));

    // String comparison
    int comp = strncmp(name, mutable_name, strlen(name));
    char * ans = comp == 0 ? "Yes" : "No";
    printf("Are names equal? -> %s\n", ans);

    char * first_name = "Isaac";
    comp = strncmp(first_name, name, strlen(first_name));
    ans = comp == 0 ? "Yes" : "No";
    printf("Are first names equal? %s\n", ans);

    // String concatenation
    char other_name[] = " Archimedes";
    strncat(mutable_name, other_name, 5);
    printf("Result of concatenation: %s\n", mutable_name);
    return 0;
}
