#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(){

	pid_t pids[3];
	for(int i = 0; i < 3; i++){
		pids[i] = fork();
		if(pids[i] == 0){
			sleep(2);
			return 1;
		}
	}

	pid_t pid;
	
	while(1){
		sleep(2);
		pid = waitpid(-1, NULL, WNOHANG);
		
		if(pid == 0)  printf("Nenhum filho terminou\n");  //no children finished
		else if((pid == -1) && (errno == ECHILD)) break;  //all children finished
		else printf("Meu filho pid=%d terminou\n", pid);  //child finished
	}
	
}
