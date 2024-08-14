#include<stdio.h>


int main(){
    char list[30] = {0};
    int i, numread, numwrite;
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

    for(i=0; i<26; i++) {
        list[i] = 'a'+ i;
    }
    numwrite = fwrite(list, sizeof(char), 26, stream1);
    printf("write %d\n", numwrite);
    
   


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

    numread = fread(list, sizeof(char), 26, stream2);
    printf("read %d\n", numread);
    printf("content:%s\n", list);
  


     



    if(fclose(stream2) == EOF) {
        printf("Error closing file 2.txt\n");
        return 1;

    } 
    return 0;
}