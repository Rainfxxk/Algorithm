#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void minAndSecondMin(int *arr, int length, int *min, int *second_min) {
    if(length == 1) {
        *min = *arr;
        *second_min = *arr;
        return;
    }
    if(length == 2) {
        if(arr[0] > arr[1]) {
            *second_min = arr[0];
            *min = arr[1];
        }
        else {
            *min = arr[0];
            *second_min = arr[1];
        }

        return;
    }

    int *min_temp;
    int *second_min_temp;
    min_temp = (int *)calloc(1, sizeof(int));
    second_min_temp = (int *)calloc(1, sizeof(int));
    *min_temp = INT_MAX;
    *second_min_temp = INT_MAX;
    int div_length = length / 2;
    minAndSecondMin(arr, div_length, min_temp, second_min_temp);

    if(*min < *min_temp) {
        *second_min = *second_min > *min_temp? *min_temp : *second_min;
    }
    else {
        *second_min = *min > *second_min_temp? *second_min_temp : *min;
        *min = *min_temp;
    }
    minAndSecondMin(arr + div_length, length - div_length, min_temp, second_min_temp);
    if(*min < *min_temp) {
        *second_min = *second_min > *min_temp? *min_temp : *second_min;
    }
    else {
        *second_min = *min > *second_min_temp? *second_min_temp : *min;
        *min = *min_temp;
    }
    free(min_temp);
    free(second_min_temp);
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

    int *min;
    int *second_min;
    min = (int *)calloc(1, sizeof(int));
    second_min = (int *)calloc(1, sizeof(int));
    *min = INT_MAX;
    *second_min = INT_MAX;

    minAndSecondMin(arr, length, min, second_min);

    printf("min: %d, the second min num: %d\n", *min, *second_min);
}