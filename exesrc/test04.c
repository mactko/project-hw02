#include <stdio.h>
#include "../src/cmplx.c"
#include "../src/io.c"

int main(){
    int N = 3;

    cmplx_t a = {0, 1};
    cmplx_t b = {1, 0};

    if((cmplx_phs(a) - M_PI/2) < 0.00001 && (cmplx_phs(b) - 0) < 0.00001){
        printf("\nSuccess!\n");
    }else{
        printf("\nFailed!\n");
    }
    return 0;
}