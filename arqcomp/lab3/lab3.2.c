#include <stdio.h>
#include <limits.h>

int main(){

	int a = INT_MAX, b = INT_MAX;
	long c = (long)a*b;
	printf("%ld\n", c);
	
}
