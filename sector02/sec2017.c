#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
 
#ifdef OPEN_MAX
static long openmax = OPEN_MAX; 
#else
static long openmax = 0;
#endif
 
/* If OPEN_MAX is indeterminate ,no gurante this is adequate */
#define OPEN_MAX_GUESS 256
 
long open_max(void)
{
   if(openmax == 0){
	errno = 0;
	if((openmax = sysconf(_SC_OPEN_MAX)) < 0) 
	{
	     printf("1.openmax= %ld\n",openmax);
	     if(errno == 0){
		 openmax = OPEN_MAX_GUESS; /*it's indeterminate*/
	     }else{
		 printf("sysconf error for _SC_OPEN_MAX");
	     }	
	}
   }
   printf("2.openmax= %ld\n",openmax);

   return(openmax);
}

int main(void)
{

  open_max();
  return 0;
}
