#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dirp;
    struct dirent *entry;

    dirp = opendir("./test");
    if(dirp == NULL) {
        printf("open error\n");
        return -1;
    }

    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }
        printf("type: %s, name: %s\n", (entry->d_type == DT_DIR)? "directory" : "file", entry->d_name);



    }
    closedir(dirp);


    return 0;

}