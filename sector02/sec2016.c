#include "../common/apue.h"
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef PATH_MAX
static int pathmax = PATH_MAX;
#else
static int pathmax=0;
#endif

#define SUSV3 200112L
static long posix_version=0;
#define PATH_MAX_GUESS 1024

char* path_alloc(int *sizep)
{
    char *ptr;
    int size;
    if(posix_version == 0){
        posix_version = sysconf(_SC_VERSION);
    }

    if(pathmax==0){
        errno=0;
    	if((pathmax = pathconf("/",_PC_PATH_MAX))<0){
    		if(errno == 0){
    			pathmax = PATH_MAX_GUESS;
    		}else{
    			err_sys("pathconf error for _PC_PATH_MAX");
		}
    	}else{
    		pathmax++;
    	}
    }

    if(posix_version < SUSV3){
      size = pathmax;
    }

    if((ptr = malloc(size)) == NULL){
       err_sys("malloc error for pathname");
    }

    if(sizep != NULL){
       *sizep = size;
    }

    return (ptr);
}


int main(int argc,char *argv[]){

    char *str = NULL;
    int sizep = 0;

    if(argc > 2){
       printf("agrv:%s\n", argv[1]);
    }

    str = path_alloc(&sizep);

    printf("str:%s sizep:%d\n",str,sizep);

    //_exit(0);
    return 0;
}
