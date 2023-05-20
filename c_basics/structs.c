#include <stdio.h>

typedef struct point {
    int x;
    int y;
} point;

typedef struct vehicle {
    char * brand;
    int model;
} vehicle;

// Passing by value. This doesn't change the original point p
void move_point_by_value(point p) {
    p.x++;
    p.y++;
}

// This canges the original point p
void move_point_by_reference(point * p) {
    p->x++;
    p->y++;
}

int main() {
    // printf("Hello\n");
    point p;
    p.x = 1, p.y = 2;
    printf("Point p's coordinates are: (%d, %d)\n", p.x, p.y);
    move_point_by_value(p);
    printf("Point p after move by value: (%d, %d)\n", p.x, p.y);
    move_point_by_reference(&p);
    printf("Point p after move by reference: (%d, %d)\n", p.x, p.y);

    // Pointers and dereferencing
    int a = 5;
    int * a_pointer = &a;
    printf("Reference is %p and value is %d\n", a_pointer, *a_pointer);

    vehicle mycar;
    mycar.brand = "Ford";
    mycar.model = 2007;
    
    return 0;
}


