#include <stdio.h>
#include "../src/cmplx.c"
#include "../src/io.c"

int main(){
    int N = 3;

    cmplx_t a = {0, 2};
    cmplx_t b = {4, 3};

    if((cmplx_mag(a) - 2) < 0.00001 && (cmplx_mag(b) - 5) < 0.00001){
        printf("\nSuccess!\n");
    }else{
        printf("\nFailed!\n");
    }
    return 0;
}