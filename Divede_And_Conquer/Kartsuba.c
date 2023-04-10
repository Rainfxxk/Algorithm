#include <stdio.h>
#include <math.h>

int max(int a, int b) {
    if(a > b)
        return a;
    else
        return b; 
}

int size(long num) {
    int length = 0;

    while(num > 0){
        num /= 10;
        length++;
    }

    return length;
}

long karatsuba(long x, long y) {
    if(x < 10 || y < 10) {
        // printf("return %d * %d = %d\n", x, y, x * y);
        return  x * y;
    } else {
        long m, x1, x0, y1, y0, z0, z1, z2, result;
        m = max(size(x), size(y)) / 2;
        x1 = x / (int)pow(10, m);
        x0 = x - x1 * (int) pow(10, m);
        y1 = y / (int) pow(10, m);
        y0 = y - y1 * (int) pow(10, m);
        z2 = karatsuba(x1, y1);
        z0 = karatsuba(x0, y0);
        z1 = karatsuba((x1 + x0), (y1 + y0)) - z0 - z2;
        result = z2 * (int)pow(10, 2*m) + z1 * (int) pow(10, m) + z0;
        //printf("%d, %d, %d, %d, %d, %d, %d, %d\n", x0, x1, y0, y1, z0, z1, z2, result);
        return result;
    }
}

int main() {
    long a, b;

    scanf("%ld%ld", &a, &b);

    printf("%ld\n", karatsuba(a, b));

    return 0;
}
