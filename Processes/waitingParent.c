// Waiting Parent PREVENTS ZOmbie Child Creation!
#include <stdio.h>
#include <unistd.h>    //use always in Process programs
#include <sys/types.h> // has pid_t support etc.
#include <sys/wait.h>  //for wait() function

main()
{
    int signal;
    pid_t pid;
    printf("PARENT:  Before fork!\n Im a parent of ID= %d and Im going to create a new child!  \n", getpid());
    pid = fork();
    if (pid == 0)
    {
        sleep(8);
        printf("CHILD:   Im the CHILD process of id=%d \n", getpid());
    }
    else if (pid > 0)
    {
        printf("PARENT:  Im the PARENT process of id=%d, I am Waiting for my child to complete!\n", getpid());
        wait(&signal); // We Use sleep() to specify the waiting time and wait() to wait till the childcompletes its process.
        printf("PARENT:  I got signal %d from child! So Im exiting \n", signal);
    }
    else
    {
        printf("Error in forking!");
    }
}
