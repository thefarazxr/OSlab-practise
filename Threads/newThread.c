// Refer: https://dextutor.com/program-to-create-threads-in-linux/
// IMPT: https://pubs.opengroup.org/onlinepubs/9699919799/functions/pthread_join.html
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *hi()
{
    printf("Hi I am a thread. My ID is: %d", getpid());
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, hi, NULL);
    pthread_join(tid, NULL); // waits for thread to terminate --->IMPT! for getting O/P
    printf("\n I am main process. My ID is: %d \n", getpid());
}