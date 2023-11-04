#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc, char const *argv[])
{
    
    char new_dir[] = "new_dir";

    if(mkdir(new_dir, S_IRWXU| S_IRGRP | S_IXGRP) !=0)
        perror("mkdir()error");
    else if (chdir(new_dir)!=0);
        perror("first chdir() error");
    else if (chdir("..")!=0)
        perror("rmdir()error");
    else
        puts("success!");
    return 0;
}



/*
void rek_mkdir(char *path) {
    char *sep = strrchr(path, '/');
    if(sep != NULL) {
        *sep = 0;
        rek_mkdir(path);
        *sep = '/';
    }
    if(mkdir(path, 0777) && errno != EEXIST)
        printf("error while trying to create '%s'\n%m\n", path); 
}

FILE *fopen_mkdir(char *path, char *mode) {
    char *sep = strrchr(path, '/');
    if(sep) { 
        char *path0 = strdup(path);
        path0[ sep - path ] = 0;
        rek_mkdir(path0);
        free(path0);
    }
    return fopen(path,mode);
}

*/


/*

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat st = {0};

if(stat("/some/directory", &st) == -1) {
    mkdir("/some/directory", 0700);
}
*/