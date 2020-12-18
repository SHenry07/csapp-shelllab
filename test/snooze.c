# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

// 只要**休眠进程**收到一个未被忽略的信号，sleep函数就会提前返回
void sigint_handler(int sig)
{
    // sleep(3);
    // exit(0);
    return;
}

unsigned int snooze(unsigned int secs)
{
    unsigned int rc = sleep(secs);
    printf("Slept for %d of %d secs\n", secs-rc, secs);
    return rc;
}


int main(int argc, char *argv[]) 
{
   if (argc < 2) {
       printf("Usage: ./snooze <seconds>\n");
       exit(0);
   }
   int sec = atoi(argv[1]);
    if (sec > 3)
    {
        signal(SIGINT, sigint_handler);
    }
    snooze(sec);
    return 0;
}