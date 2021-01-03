#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "../common/apue.h"
 
int main()
{
	printf("hello wrold from process ID %ld \n", (long)getpid());
	exit(0);
}
