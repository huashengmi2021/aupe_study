#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void){

    char *str = "hello world!";
    fprintf(stdout,"%s\n",str);

    _exit(0);
}
