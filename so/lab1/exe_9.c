#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
	pid_t c1, c2;

   	c2 = 0;
   	c1 = fork();
   	if(c1 == 0)
   		c2 = fork();
	fork();
	if(c2 > 0)
		 fork();
	sleep(3);
	exit(0);
}
