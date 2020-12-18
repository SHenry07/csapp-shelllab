#include <stdio.h>
#include <wait.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



void unix_error(char *msg) {
    fprintf(stdout,"%s: %s\n", msg, strerror(errno));
    exit(1);
}


pid_t Fork(void) 
{
    pid_t pid;
    if ((pid = fork()) < 0) {
        unix_error("fork() failed");
    }
    return pid;
}

// 问这个程序会产生多少输出行
// int main()
// {
//     printf("hello\n");
//     Fork();
//     Fork();
//     exit(0);
// }

int main()
{
    int status;
    pid_t pid;

    printf("Hello\n");
    pid = Fork();
    printf("%d\n", !pid);
    if ( pid != 0 ) {
        if ( waitpid(-1, &status, 0) > 0 ) {
            if (WIFEXITED(status) != 0 ) {
                printf("%d\n", WEXITSTATUS(status));
            }
        }
    }
    printf("Bye\n");
    exit(2);
}