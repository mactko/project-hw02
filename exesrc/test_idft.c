#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "../src/cmplx.c"
#include "../src/io.c"
#include <math.h>

int testFunction(){

    int fs = 200;
    double T = 1.0/fs;
    int N = 100;
    cmplx_t polje[N];
    cmplx_t inputIDFT[N];
    cmplx_t outputIDFT[N];

    for(int i = 0; i < N; i++){
        float signalVal = sin(2*M_PI*i*T);
        polje[i][0] = signalVal;
        polje[i][1] = 0;
    }
    int fd = open("podatci.bin", O_RDONLY);
    if(fd == -1){
        perror("Error opening file");
        return 1;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            int vrijednost_ieee = read_word(fd);
            void *a = (void *) &vrijednost_ieee;
            float vrijednost = *((float *) a);
            inputIDFT[i][j] = vrijednost;
        }
    }
    close(fd);
    remove("podatci.bin");
    cmplx_idft(inputIDFT, outputIDFT, N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            if((outputIDFT[i][j]-polje[i][j]) > 0.000001){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    if(testFunction()==1){
        printf("\nFailed test\n");
    }else{
        printf("\nSuccessful\n");
    }
    return 0;
}