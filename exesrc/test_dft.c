#include <stdio.h>
#include "../src/io.c"
#include "../src/cmplx.c"
#include <fcntl.h>
#include <errno.h>
#include <math.h>

int testFunction(){
    int fs = 200;
    double T = 1.0/fs;
    int N = 100;
    cmplx_t polje[N];
    cmplx_t outputDFT[N];

    for(int i = 0; i < N; i++){
        float signalVal = sin(2*M_PI*i*T);
        polje[i][0] = signalVal;
        polje[i][1] = 0;
    }

    cmplx_dft(polje, outputDFT, N);
    int fd = open("podatci.bin", O_WRONLY | O_CREAT | O_TRUNC);

    if(fd == -1){
        perror("Error opening file");
        return 1;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            float vrijednost = outputDFT[i][j];
            void *a = (void *) &vrijednost;
            int vrijednost_ieee = *((int *) a);
            int vrijednost_cijeli_broj = (int) vrijednost;
            write_word(fd, vrijednost_ieee);
        }
    }
    close(fd);
    return 0;
}

int main(){
    if(testFunction() == 1){
        printf("\nFailed test\n");
    }else{
        printf("\nSuccessful\n");
    }
    return 0;
}