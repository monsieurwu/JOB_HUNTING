#include<stdio.h>


int main(){
    int year = 1996;
    int month = 5;
    int day = 30;
    int a, b, c;
    int ret;
    FILE *stream1 = NULL;
    FILE *stream2 = NULL;

    stream1 = fopen("1.txt", "a+");
    if(stream1 == NULL)
    {
        printf("Error opening file 1.txt\n");
        return 1;
    }else {
        printf("File 1.txt opened successfully.\n");
    }

    ret = fprintf(stream1, "\n%d-%d-%d\n", year, month, day);
    if(ret > 0)
    {
        printf("Data written to file 1.txt successfully.\n");
    }
    else {
        printf("Error writing to file 1.txt\n");
        return 1;
    }
    
   


    if(fclose(stream1) == EOF) {
        printf("Error closing file 1.txt\n");
        return 1;

    } 

    stream2 = fopen("2.txt", "a+");
    if(stream2 == NULL)
    {
        printf("Error opening file 2.txt\n");
        return 1;
    }else {
        printf("File 2.txt opened successfully.\n");
    }

    ret = fscanf(stream2, "%d.%d.%d", &a, &b, &c);
    if(ret > 0){
        printf("Data read from file 2.txt successfully: %d-%d-%d\n", a, b, c);
    }
    else {
        printf("Error reading from file 2.txt\n");
        return 1;
    }


     



    if(fclose(stream2) == EOF) {
        printf("Error closing file 2.txt\n");
        return 1;

    } 
    return 0;
}