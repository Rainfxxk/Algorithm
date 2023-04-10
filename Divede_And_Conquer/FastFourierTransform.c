#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI acos(-1)

typedef struct complex {
    double re;
    double im;
}complex;

void fft(complex *v, int size) {
    if(size == 1) {
        return;
    }

    complex ve[size / 2], vo[size / 2];
    complex w, t;
    for(int i = 0; i < size / 2; i++) {
        *(ve + i) = *(v + 2 * i);
        *(vo + i) = *(v + 2 * i + 1);
    }
    fft(ve, size / 2);
    fft(vo, size / 2);
    for(int k = 0; k < size / 2; k++) {
        w.re = cos(2 * PI * k / size);
        w.im = sin(2 * PI * k / size);
        t.re = w.re * vo[k].re - w.im * vo[k].im;
        t.im = w.im * vo[k].re + w.re * vo[k].im;
        v[k].re = ve[k].re + t.re;
        v[k].im = ve[k].im + t.im;
        v[k + size / 2].re = ve[k].re - t.re;
        v[k + size / 2].im = ve[k].im - t.im; 
    }
}

void ifft(complex *v, int size) {
    if(size == 1) {
        return;
    }

    complex ve[size / 2], vo[size / 2];
    complex w, t;
    for(int i = 0; i < size / 2; i++) {
        *(ve + i) = *(v + 2 * i);
        *(vo + i) = *(v + 2 * i + 1);
    }
    ifft(ve, size / 2);
    ifft(vo, size / 2);
    for(int k = 0; k < size / 2; k++) {
        w.re = cos(2 * PI * k / size);
        w.im = -sin(2 * PI * k / size);
        t.re = w.re * vo[k].re - w.im * vo[k].im;
        t.im = w.im * vo[k].re + w.re * vo[k].im;
        v[k].re = ve[k].re + t.re;
        v[k].im = ve[k].im + t.im;
        v[k + size / 2].re = ve[k].re - t.re;
        v[k + size / 2].im = ve[k].im - t.im; 
    }
}



int main() {
    srand((unsigned)time(NULL));
    int size = pow(2, rand() % 4 + 4);
    size = 4;
    printf("size: %d\n", size);
    complex *f = (complex *)calloc(size * 2, sizeof(complex));
    complex *g = (complex *)calloc(size * 2, sizeof(complex));
    complex *fg = (complex *)calloc(size * 2, sizeof(complex));
    for(int i = 0; i < size; i++) {
        (f + i)->re = rand() % 10;
        (f + i)->im = 0;
        (g + i)->re = rand() % 10;
        (g + i)->im = 0;
    }
    for(int i = 0; i < size; i++) {
        printf("%lf ", (f + i)->re);
    }
    printf("\n");
    for(int i = 0; i < size; i++) {
        printf("%lf ", (g + i)->re);
    }
    printf("\n");
    fft(f, size * 2);
    fft(g, size * 2);
    for(int i = 0; i < size * 2; i++) {
        printf("%lf + %lfi, ", (f + i)->re, (f + i)->im);
    }
    printf("\n");
    for(int i = 0; i < size * 2; i++) {
        printf("%lf + %lfi, ", (g + i)->re, (g + i)->im);
    }
    printf("\n");

    for(int i = 0; i < size * 2; i++) {
        fg[i].re = f[i].re * g[i].re - f[i].im * g[i].im;
        fg[i].im = f[i].im * g[i].re + f[i].re * g[i].im;
    }
    ifft(fg, size * 2);

    for(int i = 0; i < size * 2; i++) {
        printf("%.0lf ", (fg + i)->re / (size * 2));
    }
    printf("\n");
}

