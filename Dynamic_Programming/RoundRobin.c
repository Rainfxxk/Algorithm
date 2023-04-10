#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void copy(int *src, int *tar, int size, int n) {
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
        {
            *(tar + i * n + j) = *(src + i * n + j);
        }
    }
}

void scheduleCpt(int *schedule, int size, int n) {
    if(size == 1) {
        return;
    }
    int div_size = size / 2;
    scheduleCpt(schedule, div_size, n);
    scheduleCpt(schedule + div_size * n, div_size, n);
    copy(schedule, schedule + div_size * (n + 1), div_size, n);
    copy(schedule + div_size * n, schedule + div_size, div_size, n);
}

int main() {
    srand((unsigned)time(NULL));
    int n = pow(2, rand() % 3 + 3);
    printf("n : %d\n", n);
    int *schedule = (int *)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++) {
        *(schedule + i * n) = i + 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", *(schedule + i * n + j));
        }   
        printf("\n");
    }
    scheduleCpt(schedule, n, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", *(schedule + i * n + j));
        }   
        printf("\n");
    }
}