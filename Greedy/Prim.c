#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int ** prim(int **graph, int size) {
    int lowcost[size];
    int father[size];
    for (int i = 0; i < size; i++) {
        lowcost[i] = INT_MAX;
    }

    int **minSpanTree = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        minSpanTree[i] = (int *) calloc(size, sizeof(int));
    }

    int conncted = 0;
    int currentNode = 0;
    lowcost[0] = -1;

    while (conncted < size - 1) {
        for (int i = 0; i < size; i++) {
            if (graph[currentNode][i] > 0) {
                if (lowcost[i] != -1 && lowcost[i] > graph[currentNode][i]) {
                    lowcost[i] = graph[currentNode][i];
                    father[i] = currentNode;
                }
            }
        }

        int minCost = -1;
        for (int i = 0; i < size; i++) {
            if (minCost == -1 && lowcost[i] != -1) {
                minCost = i;
            }
            if (lowcost[i] != -1 && lowcost[minCost] > lowcost[i]) {
                minCost = i;
            }
        }
        minSpanTree[father[minCost]][minCost] = lowcost[minCost];
        minSpanTree[minCost][father[minCost]] = lowcost[minCost];
        lowcost[minCost] = -1;
        currentNode = minCost;
        conncted++;
    }

    return minSpanTree;
}

int main() {
    srand((unsigned) time(NULL));
    int size = rand() % 10 + 5;
    printf("size: %d\n", size);

    int **graph = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        graph[i] = (int *) malloc(sizeof(int) * size);
    }
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
                graph[i][j] = rand() % 9;
                graph[j][i] = graph[i][j];
        }
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", graph[i][j]);
        }
        printf("\n");
    }

    int ** minSpanTree = prim(graph, size);
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", minSpanTree[i][j]);
        }
        printf("\n");
    }

    prim(graph, size);
}