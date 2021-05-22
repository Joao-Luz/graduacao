#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int first = 0;
int a[1000];
int ind[10];
pthread_mutex_t mutex;

void* routine(void* arg) {
    int valor = *(int*)arg;
    int contador = 0;
    for(int k = 0; k < 1000; k++) {
        if(a[k] == valor) 
            contador++;
    }

    //pthread_mutex_lock(&mutex);
    if(first == 0) {
    	first = 1;
        *(int*)arg = contador; 
        return arg;
    }
    *(int*)arg = -1;
    //pthread_mutex_unlock(&mutex);
    return arg;
}

int main() {
    //pthread_mutex_init(&mutex, NULL);
    srand(time(NULL));
    for(int j = 0 ; j < 1000; j++)
        a[j] = rand() % 100;
    
    for(int m = 0; m < 10; m++) {
        ind[m] = rand() % 100;
    }
    
    pthread_t th[10];
    int i;
    
    for(i = 0; i < 10; i++) {
        int* index = malloc(sizeof(int));
        *index = ind[i];
        if(pthread_create(&th[i], NULL, routine, index) != 0) {
            perror("Failed to create!!\n");
            return 1;
        }
    }

    int resultado = 0;
    long int identificador = 0;
    for(i = 0; i < 10; i++) {
        int* times; 
        if(pthread_join(th[i], (void**)&times) != 0)
            return 2;

        if(*times != -1) {
            resultado = *times;
            identificador = pthread_self();
        }  

        free(times);
    }

    // pthread_mutex_destroy(&mutex);
    
    printf("A thread vencedora foi: %ld\nCom resultado: %d\n", identificador, resultado);

    return 0;
}
