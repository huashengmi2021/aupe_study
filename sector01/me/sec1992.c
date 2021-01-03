#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void){

    char *str = "hello world!";
    printf("%s\n",str);

    _exit(0);
}
