#include <stdio.h>
#include "../common/apue.h"
 
int main()
{
	int c;
	while((c = getc(stdin)) != EOF){
	    if(putc(c, stdout) == EOF){
		err_sys("putc error\n");
            }
        }
 
	if(ferror(stdin)){
	    err_sys("input error\n");
        }

	return 0;
}
