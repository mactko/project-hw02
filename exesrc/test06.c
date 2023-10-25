#include <stdio.h>
#include "../src/cmplx.c"
#include "../src/io.c"

int main(){
    int N = 3;

    if((cmplx_imag(1, M_PI/2) - 1) < 0.00001 && (cmplx_imag(1, 3*M_PI/2) - (-1)) < 0.00001){
        printf("\nSuccess!\n");
    }else{
        printf("\nFailed!\n");
    }
    return 0;
}