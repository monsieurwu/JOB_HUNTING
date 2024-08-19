/************************
 *
 * need to be operating in windows environment
 *  
 */
#include<stdio.h>
#include<io.h>
int traverse_file(const char *path);
int count_file_line(const char *path);
int main(){
    
    int total = traverse_file("lwip-2.1.3");
    printf("Number of lines in total: %d\n", total);
  
    return 0;
}

int traverse_file(const char *path)
{
    int count = 0;
    struct _finddata_t c_file;
    intptr_t hFile;
    char allfile[1024] = {0};
    char filepath[2048] = {0};
    sprintf(allfile, "%s\\*", path);
    hFile = _findfirst(allfile, &c_file);
    if(hFile == -1) {
        printf("No files in the directory\n");
        return -1;
    }

    do{
        if(c_file.name[0] == '.')
            continue;
        sprintf(filepath, "%s\\%s", path, c_file.name);
        if(c_file.attrib & _A_SUBDIR) {
            count += traverse_file(filepath);
        }
        else {
            
            count += count_file_line(filepath);
        }

    }while(_findnext(hFile, &c_file) == 0);
    _findclose(hFile);
    return count;
}


int count_file_line(const char *path)
{
    int c, n = 0;  // Initialize count and line number variables
    FILE *stream1 = NULL;
    stream1 = fopen(path, "a+");
    if(stream1 == NULL)
    {
        printf("Error opening file path\n");
        return -1;
    }else {
        //printf("File path opened successfully.\n");
    }

    while((c = fgetc(stream1))!= EOF)
    {
        if(c == '\n')
            n++;
    }

    n++;


    if(fclose(stream1) == EOF) {
        printf("Error closing file path\n");
        return -1;
    } 
    return n;  // Return the total number of lines in the file.

}

/*
 
*/
   
