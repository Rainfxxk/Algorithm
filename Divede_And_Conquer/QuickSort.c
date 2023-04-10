#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int *arr, int begin, int end) {
    if(begin >= end) {
        return;
    }

    int temp = arr[begin];
    int i = begin;
    int j = end;
    while(i < j) {
        while (arr[j] >= temp && j > i) {
            j--;
        }
        while (arr[i] <= temp && j > i) {
            i++;
        }
        if(j > i) {
            arr[i] += arr[j];
            arr[j] = arr[i] - arr[j];
            arr[i] = arr[i] - arr[j];
        }
    }
    arr[begin] = arr[i];
    arr[i] = temp;

    for(int k = begin; k <= end; k++) {
        printf("%d ", arr[k]);    
    }
    printf("\n");
    
    quickSort(arr, begin, i - 1);
    quickSort(arr, i + 1, end);
}

int main() {
    int length;
    srand((unsigned)time(NULL));
    length = rand() % 10 + 10;
    printf("length : %d\n", length);

    int *arr = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i++) {
        arr[i] = rand() % 100;
    }

    for(int i = 0; i < length; i++) {
        printf("%d ", arr[i]);    
    }
    printf("\n");

    quickSort(arr, 0, length - 1);
    
    for(int i = 0; i < length; i++) {
        printf("%d ", arr[i]);    
    }
    printf("\n");

    /*int * arr = (int*) malloc(sizeof(int) * 2);
    arr[0] = 18;
    arr[1] = 0;

    quickSort(arr, 0, 1);*/

    return 0;
}