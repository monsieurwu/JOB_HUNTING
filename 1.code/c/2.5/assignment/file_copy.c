#include<stdio.h>

void file_copy(char *dfile, char *sfile);


int main() {
    char *str1 = "1.txt";
    char *str2 = "2.txt";
    file_copy(str2, str1);
    printf("File copied successfully.\n");

    return 0;
}

void file_copy(char *dfile, char *sfile) {
    FILE *src = fopen(sfile, "r+");
    FILE *dest = fopen(dfile, "w+");
    char ch;

    if (src == NULL || dest == NULL) {
        printf("Error opening file.\n");
        return;
    }
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
    fclose(src);
    fclose(dest);
    
}

