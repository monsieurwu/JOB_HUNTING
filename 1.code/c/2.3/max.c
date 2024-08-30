#include <stdio.h>


int *max(int *a, int *b);
int main(){
	int x = 100, y = 100;
	int *p = NULL;
    p = max(&x, &y);
    printf("The maximum value is %d\n", *p);
	return 0;
}

int *max(int *a, int *b)
{
    if(*a > *b)
        return a;
    else if(*a = *b)
    {
        int i;
        return &i;
    }    
    else
        return b;


}