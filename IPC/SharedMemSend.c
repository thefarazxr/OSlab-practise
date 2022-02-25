#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main()
{
    char *s;
    int shmid = shmget(1234, 20, IPC_CREAT | 0666); // IPC_CREAT|0666 means->chnnel fr communctn and 0666-> permissns fr READ,WRITE
    s = shmat(shmid, NULL, 0);                      // shared_memory AT has=> id, location(address), flag
    printf("Enter a message:\n");
    scanf("%s", s);
}