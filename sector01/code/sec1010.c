#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "../common/apue.h"
#define MAXLINE 4096 
 
static void  sig_int(int); // our signal-catching function
 
int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;
 
	if(signal(SIGINT, sig_int) == SIG_ERR)
	{
		err_sys("signal error");
		/*add for exit this program*/
		exit(0);
	}

	printf("%%"); /* printf prompt (printf requires %% to print %) */

	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		if (buf[strlen(buf) - 1] == '\n'){
			buf[strlen(buf) - 1] = '\0'; // replace new line witg null
                }
 
		if ((pid = fork()) < 0)
		{
			err_sys("fork error\n");
		}
		else if(pid == 0)
		{ 
			execlp(buf, buf , NULL);
			err_ret("couldn't execute: %s \n", buf);
			exit(127);
		}
 
                /*parent*/
		if((pid = waitpid(pid, &status, 0) < 0))
		{
 
			err_sys("waitpid error");
		}
		printf("%% ");
 
	}
	exit(0);
}
 
void sig_int(int signo)
{
	printf("interrupt\n %%");
}
