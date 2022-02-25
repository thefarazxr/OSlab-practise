// Reference: https://dextutor.com/difference-between-the-working-of-system-and-execl-functions/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
main()
{
    int signal;
    pid_t pid;
    printf("\nhi i am parent process i am going to create a child\n");
    pid = fork();
    if (pid == 0)
    {
        printf("\nhi i am child process. i am going to jump to a different parent process\n");
        execl("/bin/ls", "ls", "-l", NULL);
        // The execl() function replaces the current process image with a new process image specified by path
    }
    else if (pid > 0)
    {
        printf("\nhi i am parent. i will wait for my child to complete\n");
        wait(&signal);
        printf("\ni got signal=%d so my child jumped to another process.i am exiting \n", signal);
    }
    else if (pid < 0)
        printf("\nerror creating process\n");
    else
        printf("\nunknown error\n");
}