#include <stdio.h>
#include <time.h>


#define SIZE 2048


void copyij(int src[SIZE][SIZE], int dst[SIZE][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            dst[i][j] = src[i][j];
        }
    }
}

void copyji(int src[SIZE][SIZE], int dst[SIZE][SIZE]) {
    int i, j;

    for(j = 0; j < SIZE; j++) {
        for(i = 0; i < SIZE; i++) {
            dst[i][j] = src[i][j];
        }
    }
}


int src[SIZE][SIZE];
int dst[SIZE][SIZE];

int main() {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            src[i][j] = i * j;
        }
    }

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            dst[i][j] = 0;
        }
    }
    
    clock_t begin = clock();
    copyji(src, dst);  // Takes ~70ms 
    clock_t end = clock();

    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    time_spent *= 1000;

    printf("copyji time taken: %.2f ms.\n", time_spent);

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            dst[i][j] = 0;
        }
    }

    begin = clock();
    copyij(src, dst);  //Takes ~8ms
    end = clock();
    time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    time_spent *= 1000;
    printf("copyij time taken: %.2f ms.\n", time_spent);
}
