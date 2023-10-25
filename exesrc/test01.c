#include <stdio.h>
#include "../src/cmplx.c"
#include "../src/io.c"

int main(){
    int N = 3;
    float real[2] = {0.6, 1.5};
    float imag[2] = {-0.2, 0.5};

    cmplx_t a = {1, 1};
    cmplx_t b = {1, 2};
    cmplx_t c;

    cmplx_div(a, b, c);
    if((c[0] - real[0]) < 0.0001 || (c[1] - imag[0]) < 0.0001){
        cmplx_div(b, a, c);
        if((c[0] - real[1]) < 0.0001 || (c[1] - imag[1]) < 0.0001){
            printf("\nSuccess!\n");
            return 0;
        }
    }
    printf("\nFailed!\n");
    return 0;
}