
#include <stdio.h>
#include <unistd.h>
#include "../common/apue.h"

int main()
{
	printf("uid = %d , gid = %d \n", getuid(), getgid());
	exit(0);
}
