#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MSG "Meu filho, crie e envie para o seu irmão um array de números inteiros com valores randômicos entre 1 e o valor enviado anteriormente. O tamanho do array também deve ser randômico, na faixa de 1 a 10"
#define MSG_LEN strlen(MSG)

int pipe1[2];
int pipe2[2];
int pipe3[2];

void p1(){
	// fechando pipes nao utilizados
	close(0);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe3[0]);
	close(pipe3[1]);

	// lendo o valor de x e a mensagem enviada por p0 via pipe1
	int x;
	char msg[MSG_LEN + 1];
	read(pipe1[0], &x, sizeof(int));
	read(pipe1[0], msg, MSG_LEN);

	// imprimindo mensagem na tela
	msg[MSG_LEN] = 0;
	printf("%s\n", msg);

	// gerando array aleatorio e enviando para p2 via pipe2
	int size = rand() % (10) + 1;
	int* arr = malloc(sizeof(int)*size);
	for(int i = 0; i < size; i++){
		arr[i] = rand() % (x+1);
	}
	write(pipe2[1], &size, sizeof(int));
	write(pipe2[1], arr, sizeof(int)*size);
	free(arr);
	
	exit(0);
}

void p2(){
	// fechando pipes nao utilizados
	close(0);
	close(1);
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[1]);
	close(pipe3[0]);

	// lendo o tamanho e o array aleatorio criado por p1 via pipe2
	int size;
	read(pipe2[0], &size, sizeof(int));
	int* arr = malloc(size*sizeof(int));
	read(pipe2[0], arr, size*sizeof(int));

	// somando seus valores
	int sum = 0;
	for(int i = 0; i < size; i++){
		sum += arr[i];
	}
	free(arr);

	// enviando para p0 via pipe3
	write(pipe3[1], &sum, sizeof(int));
	exit(0);
}

int main(){
	int x;
	scanf("%d", &x);

	// criando pipes
	pipe(pipe1);
	pipe(pipe2);
	pipe(pipe3);

	// criando filhos
	int child = fork();
	if(child == 0) p1();
	if(child > 0){
		if(fork() == 0) p2();
		// fechando pipes nao utilizados
		close(pipe1[0]);
		close(pipe2[0]);
		close(pipe2[1]);
		close(pipe3[1]);

		// enviando o valor de x e a mensagem para p1 via pipe1
		write(pipe1[1], &x, sizeof(int));
		write(pipe1[1], MSG, MSG_LEN);

		// lendo a soma do array aleatorio vindo de p2 via pipe3
		int sum;
		read(pipe3[0], &sum, sizeof(int));
		printf("%d\n", sum);
	}
	return 0;
}
