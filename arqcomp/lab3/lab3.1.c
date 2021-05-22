#include <stdio.h>
#include <limits.h>

int main(){

	unsigned int a = UINT_MAX, b = UINT_MAX;
	printf("%u + %u = %u\n", a, b, a+b);
	printf("%u\n", b - 0);
	
}
