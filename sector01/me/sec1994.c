#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFSIZE 13

int main(void){

    int n;
    char buf[BUFFSIZE];

    fread(buf,1,BUFFSIZE,stdin);
    fwrite(buf,1,BUFFSIZE,stdout);
    
    printf("\n");      
    _exit(0);
}
