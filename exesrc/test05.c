#include <stdio.h>
#include "../src/cmplx.c"
#include "../src/io.c"

int main(){
    int N = 3;

    if((cmplx_real(1, 0) - 1) < 0.00001 && (cmplx_real(1, M_PI) - (-1)) < 0.00001){
        printf("\nSuccess!\n");
    }else{
        printf("\nFailed!\n");
    }
    return 0;
}