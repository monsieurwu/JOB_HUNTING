#include <stdio.h>
#define ARR_SIZE 100
int main(){
	int space=0, newline=0, others=0;
	int arr[ARR_SIZE] = {0};
	int c;
	printf("input: ");
	while((c=getchar()) != EOF){
		if(c >= '0' && c <= '9')
		    arr[c-'0']++;
		else if(c == ' ')
			space++;
		else if(c == '\n')
		    newline++;
		else
		    others++;

	}
	printf("output:\n");
	printf("Numbers: ");
	for(int i=0; i<10; i++)
        printf("%d ", arr[i]);
    printf("\nSpaces: %d\nNewlines: %d\nOthers: %d\n", space, newline, others);

    return 0;


	return 0;
}

