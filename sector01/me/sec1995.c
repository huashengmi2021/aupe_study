#include <stdio.h>
#include <unistd.h>
#include "../common/apue.h"

#define BUFFSIZE 4096
 
int main()
{
	int n;
	char buf[BUFFSIZE];
 
	while((n = read(0, buf, BUFFSIZE)) >0 )
	{
           if(write(1,buf, n) != n){
	       err_sys("write  error");
           }
	}

	if(n < 0){
	   err_sys("read error");
	}

	_exit(0);
}
