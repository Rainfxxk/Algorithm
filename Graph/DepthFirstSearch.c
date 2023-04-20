#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum state{
    WHITE, GREY, BLACK
} state;

void DFS_Recurse(int *graph, int size, int node, state states[]) {
    printf("node: %d\n", node);
    states[node] = GREY;
    for(int i = 0; i < size; i++) {
        if(*(graph + size * node + i) == 1 & states[i] == WHITE) {
            DFS_Recurse(graph, size, i, states);
        }
    }
    states[node] = BLACK;
    
    for (int i = 0; i < size; i++) {
        printf("%d ", states[i]);
    }
    printf("\n");
}

void DFS(int *graph, int size) {
    state states[size];
    for (int i = 0; i < size; i++) {
        states[i] = WHITE;
    }

    for (int i = 0; i < size; i++) {
        if (states[i] == WHITE) {
            DFS_Recurse(graph, size, i, states);
        }
    }
}

void DFS_Non_Recurse(int *graph, int size) {

    printf("DFS_Non_Recurse\n");
    int stack[size];
    int *top = stack - 1;

    state states[size];
    for (int i = 0; i < size; i++) {
        states[i] = WHITE;
    }

    for (int i = 0; i < size; i++) {
        if (states[i] == WHITE) {
            *(++top) = i;
            states[i] = GREY;

            while (top != stack - 1) {
                int node = *top;

                int next_node = -1;

                for (int i = 0; i < size; i++) {
                    if (*(graph + size * node + i) == 1 & states[i] == WHITE) {
                        next_node = i;
                        break;
                    }
                }

                if (next_node != -1) {
                    *(++top) = next_node;
                    states[next_node] = GREY;
                }
                else {
                    top--;
                    states[node] = BLACK;

                    for (int i = 0; i < size; i++) {
                        printf("%d ", states[i]);
                    }
                    printf("\n");
                }
            }

        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    int size = rand() % 10 + 5;
    int *graph = (int *)calloc(size * size, sizeof(int));

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            *(graph + size * i + j) = rand() % 2;
            *(graph + size * j + i) = *(graph + size * i + j);
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", *(graph + size * i + j));
        }
        printf("\n");
    }

    DFS(graph, size);
    DFS_Non_Recurse(graph, size);
}