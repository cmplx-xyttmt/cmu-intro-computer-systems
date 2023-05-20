#include <stdio.h>
#include <stdlib.h>

void print_pascals_traingle(int nrows) {
    int **triangle = (int **) malloc(nrows * sizeof(int *));

    // Generate triangle
    for(int i = 0; i < nrows; i++) {
        triangle[i] = (int *) malloc((i + 1) * sizeof(int));
        for(int j = 0; j < i + 1; j++) {
            if(i - 1 < 0 || j - 1 < 0 || j >= i) triangle[i][j] = 1;
            else triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
        }        
    }
    
    // Print triangle
    for(int i = 0; i < nrows; i++) {
        for(int j = 0; j < i + 1; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
        free(triangle[i]); // Free memory for each row
    }
    free(triangle); // Free memory for the whole array
}

int main() {
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char * pvowels = vowels; // Pointer to the first element in the vowels array
    int i;
    // Print the references
    for(i = 0; i < 5; i++) {
        printf("&vowels[%d]: %p, pvowels + %d: %p, vowels + %d: %p\n", i, &vowels[i], i, pvowels + i, i, vowels + i);
    }

    // Print the values
    for(i = 0; i < 5; i++) {
        printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", i, vowels[i], i, *(pvowels + i), i, *(vowels + i));
    }

    // TODO: Add 2d array example of Pascal's triangle, with dynamically allocated memory
    int nrows = 10;
    print_pascals_traingle(nrows);
}
