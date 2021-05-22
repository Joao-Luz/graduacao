#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigaction_child(int sig){
	FILE* dados = fopen("dados.txt", "w");
	fprintf(dados, "%d\n", 30);
	fclose(dados);
}

void handle_sigation_parent(int sig){
	FILE* dados = fopen("dados.txt", "r");
	int n; fscanf(dados, "%d", &n);
	printf("The number in the file is %d\n", n);
	fclose(dados);
	fclose(fopen("dados.txt", "w"));
}

int main(){
	struct sigaction sa;
	sigset_t blockmask;
	sigemptyset(&blockmask);
	sigaddset(&blockmask, SIGINT);
	sa.sa_mask = blockmask;
	sa.sa_flags = 0;
	
	int pid = fork();
	if(pid > 0){
		sa.sa_handler = &handle_sigation_parent;
		sigaction(SIGUSR1, &sa, NULL);
		pause();
		kill(pid, SIGUSR1);
	}

	else{
		sa.sa_handler = &handle_sigaction_child;
		sigaction(SIGUSR1, &sa, NULL);
		kill(getppid(), SIGUSR1);
		pause();
	}
}
