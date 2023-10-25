#include<stdio.h>
#include "cmplx.h"
#include <math.h>

#define M_PI 3.14159265358979323846

void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c){
    if(b[0]==0 && b[1] == 0){
        printf("Can't divide by zero");
        return;
    }
    c[0]=(a[0]*b[0]+a[1]*b[1])/(b[0]*b[0]+b[1]*b[1]);
    c[1]=(a[1]*b[0]-a[0]*b[1])/(b[0]*b[0]+b[1]*b[1]);
}

void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c){
    c[0]=a[0]*b[0]-a[1]*b[1];
    c[1]=a[0]*b[1]+a[1]*b[0];
}

double cmplx_mag(cmplx_t a){
    return sqrt(a[0]*a[0]+a[1]*a[1]);
}

double cmplx_phs(cmplx_t a){
    return atan2(a[1], a[0]);
}

double cmplx_real(double mag, double phs){
    return mag * cos(phs);
}

double cmplx_imag(double mag, double phs){
    return mag * sin(phs);
}

void cmplx_dft(cmplx_t *input, cmplx_t *output, int N){
    float inreal[N];
    float inimag[N];
    for(int i = 0; i < N; i++){
        inreal[i] = input[i][0];
        inimag[i] = input[i][1];
    }
    for(int k = 0; k < N; k++){
        double sumreal = 0;
        double sumimag = 0;
        for(int t = 0; t < N; t++){
            double phs = 2*M_PI*t*k/N;
            sumreal += inreal[t] * cos(phs) + inimag[t] * sin(phs);
            sumimag += -inreal[t] * sin(phs) + inimag[t] * cos(phs);
        }
        output[k][0] = sumreal;
        output[k][1] = sumimag;
    }
}

void cmplx_idft(cmplx_t *input, cmplx_t *output, int N){
    float inreal[N];
    float inimag[N];
    for(int i = 0; i < N; i++){
        inreal[i] = input[i][0];
        inimag[i] = input[i][1];
    }
    for(int k = 0; k < N; k++){
        double sumreal = 0;
        double sumimag = 0;
        for(int t = 0; t < N; t++){
            double phs = 2*M_PI*t*k/N;
            sumreal += inreal[t] * cos(phs) - inimag[t] * sin(phs);
            sumimag += inreal[t] * sin(phs) + inimag[t] * cos(phs);
        }
        output[k][0] = sumreal/N;
        output[k][1] = sumimag/N;
    }
}