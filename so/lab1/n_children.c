#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if(argc <= 1){
		printf("Input N missig. Exiting...\n");
		return 1;
	}

	int n = atoi(argv[1]);

	for(int i = 0; i < n; i++){

		pid_t child_pid = fork();
		if(child_pid < 0){
			printf("Failed to fork...\n");
			return 1;
		}

		else if(child_pid == 0) break;
	}

	sleep(10);
	return 0;
}
