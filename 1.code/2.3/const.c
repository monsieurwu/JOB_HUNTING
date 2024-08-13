#include <stdio.h>



int main(){
	int x = 100, y = 30;
	int *const p = &x;
	//p = &x;
	p = &y;
	

	printf("x = %d, &x: %p\n", x, &x);
	printf("p = %d, *p = %p\n", *p, p);
	return 0;
}
