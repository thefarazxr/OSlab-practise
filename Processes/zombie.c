// Waiting Parent PREVENTS ZOmbie Child Creation!
#include <stdio.h>
#include <unistd.h> //use always in Process programs
// #include <sys/types.h> // has pid_t support etc.
// #include <sys/wait.h>  //for wait() function

main()
{
    pid_t pid;
    printf("PARENT:  Before fork!\n Im a parent of ID= %d and Im going to create a new child!  \n", getpid());
    pid = fork();
    if (pid == 0)
    {
        printf("CHILD:   Im the CHILD process of id=%d now Leaving BYEE! \n", getpid());
    }
    else if (pid > 0)
    {
        printf("PARENT:  Im the PARENT process of id=%d Gonna PAUSE for some time\n", getpid());
        pause();

        // use command : ps to see is my child still existing (ZOMBIE ?)
    }
    else if (pid < 0)
    {
        printf("Error in forking!");
    }
}
