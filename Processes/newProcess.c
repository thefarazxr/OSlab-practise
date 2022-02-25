
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
main()
{
    pid_t pid;
    printf("Before fork!\n");
    pid = fork();
    printf("Common Area/Task-1 accessed by id=%d\n", getpid());
    if (pid == 0)
    {

        printf("Im the CHILD process of id=%d \n", getpid());
        printf("My parent's id=%d \n", getppid());
    }
    else
    {

        printf("My child's id=%d \n", pid);
        printf("Im the PARENT process of id=%d \n", getpid());
    }
    printf("Common Area/Task-2 accessed by id=%d\n", getpid());
}

// As once Parent is done next child Process becomes orphan
//  if not became orphan then try to add sleep to child so that in mean time parent porcess ENDs executing!!