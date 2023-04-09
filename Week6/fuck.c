#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define q 8      /* 2^q 点，256 */
#define N (1<<q)  /* N点 FFT, iFFT */

typedef float real;
typedef struct{
  real Re; 
  real Im;
} complex;

#ifndef PI
# define PI 3.14159265358979323846264338327950288
#endif

/*为了更好说明分治思想，这里采用递归实现，结束条件为N<=1*/
void fft( complex *v, int n)
{
  if(n>1) {   /* N如小于1，直接返回*/
    int k,m;    complex z, w, vo[n / 2], ve[n / 2];
    for(k=0; k<n/2; k++) {
      ve[k] = v[2*k];
      vo[k] = v[2*k+1];
    }
    fft( ve, n/2 );  /* FFT 偶数序列 v[] */
    fft( vo, n/2 );  /* FFT 偶数序列 v[] */
    for(m=0; m<n/2; m++) {
      w.Re = cos(2*PI*m/(double)n);
      w.Im = -sin(2*PI*m/(double)n);
      z.Re = w.Re*vo[m].Re - w.Im*vo[m].Im; /* Re(w*vo[m]) */
      z.Im = w.Re*vo[m].Im + w.Im*vo[m].Re; /* Im(w*vo[m]) */
      v[  m  ].Re = ve[m].Re + z.Re;
      v[  m  ].Im = ve[m].Im + z.Im;
      v[m+n/2].Re = ve[m].Re - z.Re;
      v[m+n/2].Im = ve[m].Im - z.Im;
    }
  }
  return;
}

/*为了更好说明分治思想，这里采用递归实现，结束条件为N<=1*/
void ifft( complex *v, int n )
{
  if(n>1) {   
    int k,m;    complex z, w, vo[n / 2], ve[n / 2];
    for(k=0; k<n/2; k++) {
      ve[k] = v[2*k];
      vo[k] = v[2*k+1];
    }
    fft( ve, n/2 );  /* FFT 偶数序列 v[] */
    fft( vo, n/2 );  /* FFT 偶数序列 v[] */
    for(m=0; m<n/2; m++) {
      w.Re = cos(2*PI*m/(double)n);
      w.Im = sin(2*PI*m/(double)n);
      z.Re = w.Re*vo[m].Re - w.Im*vo[m].Im; /* Re(w*vo[m]) */
      z.Im = w.Re*vo[m].Im + w.Im*vo[m].Re; /* Im(w*vo[m]) */
      v[  m  ].Re = ve[m].Re + z.Re;
      v[  m  ].Im = ve[m].Im + z.Im;
      v[m+n/2].Re = ve[m].Re - z.Re;
      v[m+n/2].Im = ve[m].Im - z.Im;
    }
  }
  return;
}

#define SAMPLE_RATE (10000.0f)
int main(void)
{   srand((unsigned)time(NULL));
    int size = pow(2, rand() % 4 + 4);
    size = 4;
    printf("size: %d\n", size);
    complex *f = (complex *)calloc(size * 2, sizeof(complex));
    complex *g = (complex *)calloc(size * 2, sizeof(complex));
    complex *fg = (complex *)calloc(size * 2, sizeof(complex));
    for(int i = 0; i < size; i++) {
        (f + i)->Re = rand() % 10;
        (f + i)->Im = 0;
        (g + i)->Re = rand() % 10;
        (g + i)->Im = 0;
    }
    for(int i = 0; i < size; i++) {
        printf("%lf ", (f + i)->Re);
    }
    printf("\n");
    for(int i = 0; i < size; i++) {
        printf("%lf ", (g + i)->Re);
    }
    printf("\n");
    fft(f, size * 2);
    fft(g, size * 2);
    for(int i = 0; i < size * 2; i++) {
        printf("%lf + %lfi, ", (f + i)->Re, (f + i)->Im);
    }
    printf("\n");
    for(int i = 0; i < size * 2; i++) {
        printf("%lf + %lfi, ", (g + i)->Re, (g + i)->Im);
    }
    printf("\n");

    for(int i = 0; i < size * 2; i++) {
        fg[i].Re = f[i].Re * g[i].Re - f[i].Im * g[i].Im;
        fg[i].Im = f[i].Im * g[i].Re + f[i].Re * g[i].Im;
    }
    
    ifft(fg, size * 2);

    for(int i = 0; i < size * 2; i++) {
        printf("%lf + %lfi ", (fg + i)->Re, (fg + i)->Im);
    }
    printf("\n");
}