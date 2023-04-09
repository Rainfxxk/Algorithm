#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maxAndMin(int *arr, int length, int *max, int *min) {
    if(length == 1) {
        *max = *arr;
        *min = *arr;
        
        return;
    }
    if(length == 2) {
        if(arr[0] > arr[1]) {
            *max = arr[0];
            *min = arr[1];
        }
        else {
            *min = arr[0];
            *max = arr[1];
        }

        return;
    }

    int *max_temp;
    int *min_temp;
    max_temp = (int *)calloc(1, sizeof(int));
    min_temp = (int *)calloc(1, sizeof(int));
    *min_temp = *arr;
    int div_length = length / 2;
    maxAndMin(arr, div_length, max_temp, min_temp);
    *max = *max > *max_temp? *max : *max_temp;
    *min = *min < *min_temp? *min : *min_temp;
    maxAndMin(arr + div_length, length - div_length, max_temp, min_temp);
    *max = *max > *max_temp? *max : *max_temp;
    *min = *min < *min_temp? *min : *min_temp;
    free(max_temp);
    free(min_temp);
}

int main() {
    srand((unsigned)time(NULL));
    int length = rand() % 10 + 10;
    printf("length: %d\n", length);
    int *arr = (int *) calloc(length, sizeof(int));
    for(int i = 0; i < length; i++) {
        *(arr + i) = rand() % 100;
        printf("%d ", *(arr + i));
    }
    printf("\n");

    int *max, *min;
    max = (int *)calloc(1, sizeof(int));
    min = (int *)calloc(1, sizeof(int));
    *min = *arr;
    maxAndMin(arr, length, max, min);

    printf("max: %d, min: %d\n", *max, *min);
}