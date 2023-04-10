#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void move(char from, char to) {
    printf("%c -> %c\n", from, to);
}

void hanNo(int n, char A, char B, char C) {
    if(n == 1) {
        move(A, C);
    }
    else {
        hanNo(n-1, A, C, B);
        move(A, C);
        hanNo(n-1, B, A, C);
    }
}

int main() {
    int start = time(NULL);
    srand((unsigned) time(NULL));
    int n = rand() % 10 + 3;
    printf("%d\n", n);
    hanNo(30, 'A', 'B', 'C');
    int end = time(NULL);
    printf("%d\n", end - start);
}