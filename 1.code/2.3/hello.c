#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int make_rand_num(void);
int get_user_input(void);
int main(){
	int random;
	int input;
	random = make_rand_num();
	do{
	input = get_user_input();
	if(input > random){
		printf("too big!\n");
	}
	else if(input == random){

		printf("correct!\n");

	}else {
		printf("too small\n");
	}
	}while(input != random);
	return 0;
}

int make_rand_num(void)
{
	srand(time(NULL));
	int random = rand() % 100 + 1;
	return random;
}

int get_user_input(void)
{
	int a;
	printf("input your guess number: ");
	scanf(" %d", &a);
	return a;
}
