#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<direct.h>
#include<errno.h>

int main(void)
{
    char buffer[20];
    char *retptr = _getcwd(NULL, 1024);
    char path[128];
    getcwd(path,128);
    // check if an error occurred 
    if(retptr == NULL)
    {
        printf("Get current working directory failed.\n");

        if (errno == ERANGE)
        printf("path exceeds max buffer length. \n");
        else if (errno == ENOMEM)
        printf("Memory can't be allocated");

        return 1;
    }

    printf("\n\ncurrent working: %s",path);
    free(retptr);
    return 0;
}