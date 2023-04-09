#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    
    quickSort(arr, begin, i - 1);
    quickSort(arr, i + 1, end);
}

int getMid(int *arr, int start, int end) {
    if(end - start + 1 <= 5) {
        quickSort(arr, start, end);
        return arr[(start + end) / 2];
    }

    int length = (end - start + 1) / 5;
    int temp[length];
    for(int i = 0; i < length; i++) {
        temp[i] = getMid(arr, start + i * 5, start + (i + 1) * 5  - 1);
    }

    return getMid(temp, 0, length);
}

int Select(int *arr, int size, int position) {
    int result;
    int *arr_temp = (int *)calloc(size, sizeof(int));
    memcmp(arr_temp, arr, size);
    // if(size <= 75) {
    //     quickSort(arr_temp, 0, size);
    //     return arr[position];
    // }

    int mid = getMid(arr_temp, 0, size - 1);

    int right = 0, left = size - 1;
    while(right < left) {
        while(arr[right] < mid && right < left){
            right++;
        }
        while(arr[left] > mid && right < left) {
            left++;
        }
        if(right <= left) {
            arr[right] += arr[left];
            arr[left] = arr[right] - arr[left];
            arr[right] = arr[right] - arr[left];
        }
    }

    if(right == position) {
        result = arr_temp[right];
        free(arr_temp);
        return result;
    }
    else if(position < right) {
        result = Select(arr, right, position);
        free(arr_temp);
        return result;
    }
    else {
        result = Select(arr + right + 1, size - right, position - size);
        free(arr_temp);
        return result;
    }
}

int main() {
    int length;
    srand((unsigned)time(NULL));
    length = rand() % 10 + 10;
    printf("length : %d\n", length);

    int *arr = (int*)malloc(sizeof(int) * length);
    int *arr_temp = (int *)calloc(length, sizeof(int));
    for(int i = 0; i < length; i++) {
        arr[i] = rand() % 100;
        arr_temp[i] = arr[i];
        printf("%d ", arr[i]);
    }
    printf("\n");

    
    //memcmp(arr_temp, arr, length * sizeof(int));
    quickSort(arr_temp, 0, length - 1);

    int position = rand() % 10 + 9;
    for(int i = 0; i < length; i++) {
        printf("%d ", arr_temp[i]);
    }
    printf("\n");

    printf("mid: %d, %d: %d\n", arr_temp[length / 2], position, arr_temp[position]);

    int mid = Select(arr, length, position);
    printf("position: %d\n", Select);

    return 0;
}