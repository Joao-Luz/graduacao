#include <time.h>
#include <unistd.h>
#include <stdio.h>

int main(){

	time_t rawtime;
	struct tm * timeinfo;
	sleep(3);
	fork();

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	printf ( "Current local time and date: %s", asctime (timeinfo) );


	  
}
