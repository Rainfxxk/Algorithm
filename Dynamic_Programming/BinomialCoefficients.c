#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *BinomialCoefficient(int n) {
    int * coe = (int *)malloc(n * sizeof(int));
    for ( int i = 0; i < n; i++) {
        *(coe + i) = 1;
    }

    for(int i = 2; i < n; i++) {
        for(int j = i - 1; j > 0; j--) {
            *(coe + j) = *(coe + j) + *(coe + j - 1);
        }
    }

    return coe;
}

int main() {
    srand((unsigned)time(NULL));
    int n = rand() % 17;
    printf("n: %d\n", n);
    int * coe = BinomialCoefficient(n);
    for (int i = 0; i < n; i++) {
        printf("%d ", *(coe + i));
    }
}