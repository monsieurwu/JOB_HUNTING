#include<stdio.h>


int main(){
    
    char str[4090] = {0};
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

    
    while((fgets(str, sizeof(str), stream1) != NULL) {
        printf("%s", str);
    }
    puts("");



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

    printf("input content, press ctrl+z to exit:\n");
    
    while((fgets(str, sizeof(str), stdin)!=NULL){
        fputs(str, stream2);
    }



    if(fclose(stream2) == EOF) {
        printf("Error closing file 2.txt\n");
        return 1;

    } 
    return 0;
}