#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int longestPath(int *graph, int size, int node) {
    int path = 0;
    for(int i = 0; i < node; i++) {
        if( *(graph + i * size + node) != 0) {
            int temp = longestPath(graph, size, i) + *(graph + i * size + node);
            printf("%d to %d: %d\n", node, i, temp);
            path = path > temp? path : temp;
        }
    }
    return path;
}

void printGraph(int *graph, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", *(graph + i * size + j));
        }
        printf("\n");
    }
}

int main() {
    srand((unsigned)time(NULL));
    int size = rand() % 5 + 5;
    printf("size: %d\n", size);
    int* graph = (int *)calloc(size, sizeof(int));

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            *(graph + i * size + j) = rand() % 10;
        }
    }

    printGraph(graph, size);

    printf("the longest path: %d\n", longestPath(graph, size, size - 1));
}