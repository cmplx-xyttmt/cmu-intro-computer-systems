#include <stdio.h>

// Memory referencing bug example
typedef struct
{
    int a[2];
    double d;
} struct_t;

double fun(int i) {
    volatile struct_t s;
    s.d = 3.14;
    s.a[i] = 1073741824; // Possibly out of bounds
    return s.d;
}

main() {
    int square40 = 40000 * 40000;
    int square50 = 50000 * 50000;
    printf("hello, world\n");
    printf("40000 * 40000 = %d\n", square40);
    printf("50000 * 50000 = %d\n", square50);

    float float1 = (1e20 + -1e20) + 3.14;
    float float2 = 1e20 + (-1e20 + 3.14);
    printf("Equal? -> %f vs %f\n", float1, float2);

    // printf("%f\n", fun(6));
    for(int i = 0; i <= 6; i++) {
        printf("fun(%d) = %f\n", i, fun(i));
    }
}
