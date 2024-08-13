#include <stdio.h>



int main(){
	int x = 100;
	int *p = NULL;
	//p = &x;

	printf("x = %d, &x: %p\n", x, &x);
	printf("p = %p\n", p);
	return 0;
}
