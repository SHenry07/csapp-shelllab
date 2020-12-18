#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[],char *envp[])
{
    printf("Command-line arguments:\n");
    for (int i = 0; i < argc; i++)
    {
        printf("   argv[%2d]: %s\n", i, argv[i]);
    }
    printf("Environment variables:\n");
    int j = 0;
    while (envp[j] != NULL)
    {
        printf("   envp[%2d]: %s\n", j, envp[j]);
        j++;
    }
}