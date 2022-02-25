#include <stdio.h>
#include <unistd.h>
main()
{
    pid_t pid;
    printf("\nhi i am parent process i am going to create a child\n");
    pid = fork();
    if (pid == 0)
        printf("\nhi i am child process. i have finished my job\n");
    else if (pid > 0)
    {
        printf("\nhi i am parent. i am going to pause\n");
        pause();
    }
    else if (pid < 0)
        printf("\nerror creating process\n");
    else
        printf("\nunknown error\n");
}