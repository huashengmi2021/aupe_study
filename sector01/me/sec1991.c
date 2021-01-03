#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void){

    char buff[100];
    memset(buff,'0',sizeof(buff));
    fread(buff,1,20,stdin);
    fwrite(buff,1,10,stdout);
    printf("\n");
 
    _exit(0);
    //return 0;
}
