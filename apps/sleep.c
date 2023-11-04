#include<stdio.h>
#include<stdlib.h>
#include<syscall.h>
#include<string.h>

int main(int argc, char ** argv){

 int ret = 0 ;
 
 if (argc <2)
   {
	fprintf(stderr, "%s: missing operand\n", argv[0]);
return 1;
   }

char * arg = strdup(argv[1]);
float time = atof(arg);
unsigned int seconds = (unsigned int)time;
unsigned int subsecs = (unsigned int)((time - (float)seconds) * 100);

ret = syscall_sleep(seconds, subsecs);

	return ret;

}


