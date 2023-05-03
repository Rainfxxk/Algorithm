#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum state {
    WHITE,
    GREY,
    BLACk
} state;

int * topologicalSort(int **graph, int size) {
    state states[size];
    for (int i = 0; i < size; i++) {
        states[i] = WHITE;
    }

    int *topological = (int *) malloc(sizeof(int) * size);
    int order = size;

    int stack[size];
    int top = -1;

    for (int i = 0; i < size; i++) {
        if (states[i] == WHITE) {
            stack[++top] = i;
            states[i] = GREY;

            while (top != -1) {
                int node = stack[top];
                int flag = 1;

                for (int j = 0; j < size; j++) {
                    if (states[j] == WHITE && graph[node][j] == 1) {
                        flag = 0;
                        stack[++top] = j;
                        states[j] = GREY;
                        break;
                    }
                }

                if (flag) {
                    topological[--order] = node;
                    top--;
                }
            }
        }
    }

    return topological;
}

int main() {
    srand((unsigned) time(NULL));
    int size = rand() % 10 + 5;
    printf("size: %d\n", size);

    int **graph = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        graph[i] = (int *) malloc(sizeof(int) * size);
        for (int j = i + 1; j < size; j++) {
                graph[i][j] = rand() % 2;
        }
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    int *topological = topologicalSort(graph, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", topological[i]);
    }
    printf("\n");
}