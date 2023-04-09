#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int *initMatrix(int size) {
    int *matrix;
    matrix = (int *)calloc(size * size, sizeof(int));
    if(!matrix) {
        printf("failed\n");
        return NULL;
    }

    return matrix;
}

void fillMatrix(int *matrix, int size) {
    for(int i = 0; i < size * size; i++) {
        *(matrix + i) = rand() % 10;
    }
}

void matrixAdd(int *a, int *b, int *result, int size) {
    for(int i = 0; i < size * size; i++) {
        *(result + i) = *(a + i) + *(b + i);
    }
}

void matrixSub(int *a, int *b, int *result, int size) {
    for(int i = 0; i < size * size; i++) {
        *(result + i) = *(a + i) - *(b + i);
    }
}

void printMatrix(int *matrix, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%4d ", *(matrix + i * size + j));
        }
        printf("\n");
    }
}

void strassen(int *a, int *b, int *c, int size) {
    if(size == 1) {
        *c = *a * *b;
        return;
    }

    int div_size = size / 2;
    int *a1 = initMatrix(div_size);
    int *a2 = initMatrix(div_size);
    int *a3 = initMatrix(div_size);
    int *a4 = initMatrix(div_size);
    int *b1 = initMatrix(div_size);
    int *b2 = initMatrix(div_size);
    int *b3 = initMatrix(div_size);
    int *b4 = initMatrix(div_size);
    int *c1 = initMatrix(div_size);
    int *c2 = initMatrix(div_size);
    int *c3 = initMatrix(div_size);
    int *c4 = initMatrix(div_size);
    int *d = initMatrix(div_size);
    int *e = initMatrix(div_size);
    int *f = initMatrix(div_size);
    int *g = initMatrix(div_size);
    int *h = initMatrix(div_size);
    int *i = initMatrix(div_size);
    int *j = initMatrix(div_size);
    int *temp1 = initMatrix(div_size);
    int *temp2 = initMatrix(div_size);
    
    for(int i = 0; i < div_size; i++) {
        for(int j = 0; j < div_size; j++) {
            *(a1 + i * div_size + j) = *(a + i * size + j);
            *(a2 + i * div_size + j) = *(a + i * size + j + div_size);
            *(a3 + i * div_size + j) = *(a + (div_size + i) * size + j);
            *(a4 + i * div_size + j) = *(a + (div_size + i) * size + j + div_size);
            *(b1 + i * div_size + j) = *(b + i * size + j);
            *(b2 + i * div_size + j) = *(b + i * size + j + div_size);
            *(b3 + i * div_size + j) = *(b + (div_size + i) * size + j);
            *(b4 + i * div_size + j) = *(b + (div_size + i) * size + j + div_size); 
        }
    }

    matrixSub(b2, b4, temp1, div_size);
    strassen(a1, temp1, d, div_size);

    matrixSub(b3, b1, temp1, div_size);
    strassen(a4, temp1, e, div_size);

    matrixAdd(a3, a4, temp1, div_size);
    strassen(temp1, b1, f, div_size);

    matrixAdd(a1, a2, temp1, div_size);
    strassen(temp1, b4, g, div_size);

    matrixSub(a3, a1, temp1, div_size);
    matrixAdd(b1, b2, temp2, div_size);
    strassen(temp1, temp2, h, div_size);

    matrixSub(a2, a4, temp1, div_size);
    matrixAdd(b3, b4, temp2, div_size);
    strassen(temp1, temp2, i, div_size);

    matrixAdd(a1, a4, temp1, div_size);
    matrixAdd(b1, b4, temp2, div_size);
    strassen(temp1, temp2, j, div_size);

    matrixAdd(e, i, c1, div_size);
    matrixAdd(c1, j, c1, div_size);
    matrixSub(c1, g, c1, div_size);

    matrixAdd(d, g, c2, div_size);
    
    matrixAdd(e, f, c3, div_size);
    
    matrixAdd(d, h, c4, div_size);
    matrixAdd(c4, j, c4, div_size);
    matrixSub(c4, f, c4, div_size);

    for(int i = 0; i < div_size; i++) {
        for(int j = 0; j < div_size; j++) {
            *(c + i * size + j) = *(c1 + i * div_size + j);
            *(c + i * size + j + div_size) = *(c2 + i * div_size + j);
            *(c + (i + div_size) * size + j) = *(c3 + i * div_size + j);
            *(c + (i + div_size) * size + j + div_size) = *(c4 + i * div_size + j);
        }
    }

    free(a1);
    free(a2);
    free(a3);
    free(a4);
    free(b1);
    free(b2);
    free(b3);
    free(b4);
    free(c1);
    free(c2);
    free(c3);
    free(c4);
    free(d);
    free(e);
    free(f);
    free(g);
    free(h);
    free(i);
    free(j);
    free(temp1);
    free(temp2);
}

int main() {
    srand((unsigned)time(NULL));
    int size = pow(2, rand() % 4 + 1);
    size = 4;
    printf("size: %d \n", size);

    printf("---------A----------\n");
    int *a = initMatrix(size);
    fillMatrix(a, size);
    printMatrix(a, size);
    
    printf("---------B----------\n");
    int *b = initMatrix(size);
    fillMatrix(b, size);    
    printMatrix(b, size);

    printf("---------C----------\n");
    int *c = initMatrix(size);
    strassen(a, b, c, size);
    printMatrix(c, size);
}