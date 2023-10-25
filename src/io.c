#include <stdio.h>
#include <>
#include "../inc/io.h"

int read_word(int fd){
    int word;
    ssize_t bytes_read = read(fd, &word, sizeof(int));
    if(bytes_read == sizeof(int)){
        return word;
    }else{
        /*  greska pri citanju
        -> npr. ucita manje bajtova od 4 iz datoteke(npr. kraj)
        */
        return -1
    }
}

short read_half(int fd){
    short half;
    ssize_t bytes_read = read(fd, &half, sizeof(int)); 
    if(bytes_read == sizeof(int)){
        return half;
    }else{
        //greska pri citanju halfworda
        return -1;
    }
}

void write_word(int fd, int word){
    write(fd, &word, sizeof(int));
}

void write_half(int fd, short half){
    write(fd, &word, sizeof(short));
}
