#include <stdlib.h>
#include <unistd.h>

int main(int argc , char *argv []){
	pid_t childpid = 0;
	int i, n;
	/*  check  for  valid  number  of command -line  arguments  */
	n = atoi(argv [1]);
	for (i = 1; i < n; i++)
		if (( childpid = fork()) ==  -1)
		break;
	sleep(3);
	return  0;
}
