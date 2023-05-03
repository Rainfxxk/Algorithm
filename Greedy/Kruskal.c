#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct edge {
    int father;
    int son;
    int weight;
} edge;

typedef struct tree {
    struct tree *father;
    int rank;
    int vertex;
} tree;

void quickSort(edge edges[], int begin, int end) {
    if (begin > end) {
        return;
    }

    edge mid = edges[begin];
    int left = begin;
    int right = end;

    while (left < right) {
        while (left < right) {
            if (edges[right].weight > mid.weight) {
                right--;
            }
            else {
                break;
            }
        }
        while (left < right) {
            if (edges[left].weight <= mid.weight) {
                left++;
            }
            else {
                break;
            }
        }
        if (left < right) {
            edge temp = edges[left];
            edges[left] = edges[right];
            edges[right] = temp;
        }
    }
    edges[begin] = edges[left];
    edges[left] = mid;

    quickSort(edges, begin, left - 1);
    quickSort(edges, left + 1, end);
}

tree *find(tree *node) {
    tree *tempNode = node;
    int temp = 0;
    while (tempNode->father != tempNode) {
        tempNode = tempNode->father;
        temp++;
    }

    return tempNode;
}

void merge(tree *node_A, tree* node_B) {
    tree *root_A = find(node_A);
    tree *root_B = find(node_B);

    tree *sonNode;
    int rank = 1;
    if (root_A->rank > root_B->rank) {
        root_B->father = node_A;
        printf("tree: %d -> %d\n", root_B->vertex, node_A->vertex);
        sonNode = node_A;
        rank += node_B->rank;
    }
    else {
        root_A->father = node_B;
        printf("tree: %d -> %d\n", root_A->vertex, node_B->vertex);
        sonNode = node_B;
        rank += node_A->rank;
    }

    do {
        sonNode->rank += rank;
        sonNode = sonNode->father;
    } while (sonNode->father != sonNode);
}

int ** kruskal(int **graph, int size) {
    tree trees[size];
    for (int i = 0; i < size; i++) {
        trees[i].father = &trees[i];
        trees[i].rank = 0;
        trees[i].vertex = i;
    }

    int **minSpanTree = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        minSpanTree[i] = (int *) calloc(size, sizeof(int));
    }

    int lenth = 0;
    edge edges[size * size];
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (graph[i][j] != 0) {
                edges[lenth].weight = graph[i][j];
                edges[lenth].father = i;
                edges[lenth].son = j;
                lenth++;
            }
        }
    }
    quickSort(edges, 0, lenth - 1);

    // for (int i = 0; i < lenth; i++) {
    //     printf("%3d ", edges[i].father);
    // }
    // printf("\n");
    // for (int i = 0; i < lenth; i++) {
    //     printf("%3d ", edges[i].weight);
    // }
    // printf("\n");
    // for (int i = 0; i < lenth; i++) {
    //     printf("%3d ", edges[i].son);
    // }
    // printf("\n");
    
    for (int i = 0; i < lenth; i++) {
        if (find(&trees[edges[i].father])->vertex != find(&trees[edges[i].son])->vertex) 
        {
            printf("Merge!  edge: %d -> %d, weight: %d\n", edges[i].father, edges[i].son, edges[i].weight);
            merge(&trees[edges[i].father], &trees[edges[i].son]);
            minSpanTree[edges[i].father][edges[i].son] = edges[i].weight;
            minSpanTree[edges[i].son][edges[i].father] = edges[i].weight;
        }
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
            graph[i][j] = rand() % 9 + 1;
            graph[j][i] = graph[i][j];
        }
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", graph[i][j]);
        }
        printf("\n");
    }

    int ** minSpanTree = kruskal(graph, size);
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", minSpanTree[i][j]);
        }
        printf("\n");
    }
}