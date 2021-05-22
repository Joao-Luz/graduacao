#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int a[1000];
long int first = 0; // contem o identificador da thread vencedora
pthread_mutex_t mutex;

void* proc(void* arg){
	int x = *(int*)arg; // converter o argumento para um inteiro
	int count = 0;
	// varrendo a
	for(int i = 0; i < 1000; i++){
		if(a[i] == x) count++;
	}
	// apenas uma thread pode modificar a variavel first de cada vez
	pthread_mutex_lock(&mutex);
	if(first == 0){
		// a thread foi a primeira a varrer a
		first = pthread_self();
		pthread_mutex_unlock(&mutex);
		return (void*)count;
	}
	pthread_mutex_unlock(&mutex);
	return (void*)-1;
}

int main(){
	srand(time(NULL)); // numeros aleatorios
	// populando o vetor a
	for(int i = 0; i < 1000; i++) a[i] = rand() % 100 + 1;

	pthread_mutex_init(&mutex, NULL);
	
	// criando as 10 threads
	pthread_t threads[10];
	for(int i = 0; i < 10; i++){
		int rand_arg = rand() % 10 + 1; // o argumento da funcao da thread
		if(pthread_create(&threads[i], NULL, proc, (void*)&rand_arg) != 0){
			perror("Não foi possível criar a thread!\n");
			return 1;
		}
	}
	// esperando o resultado de todas as threads
	for(int i = 0; i < 10; i++){
		int count;
		// quando a thread retornar, atribuir o valor a count
		pthread_join(threads[i], (void**)&count);
		// se count != -1, a thread foi a primeira a terminar de varrer a, o a variavel first contem seu id
		if(count != -1) printf("Thread vencedora: %ld com %d\n", first, count);
	}
	pthread_mutex_destroy(&mutex);
}
