#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t b; // pthread_mutex_t mutex;
sem_t r;
int buf = 0, i, rcount = 0; // track readers count

void *reader()
{
    while (1)
    {
        sleep(5);
        sem_wait(&r);
        rcount++;
        if (rcount == 1)
            sem_wait(&b); // pthread_mutex_lock(&mutex);
        printf("a reader reads buf data = %d\n", buf);
        sleep(5);
        sem_post(&r);
        rcount--;
        if (rcount == 0)
            sem_post(&b); // pthread_mutex_unlock(&mutex);
    }
}

void *writer()
{
    while (1)
    {
        sleep(2);
        sem_wait(&b); // pthread_mutex_lock(&mutex);
        buf++;
        printf("Data writen by the writer buf data = %d\n", buf);
        sleep(2);
        sem_post(&b); // pthread_mutex_unlock(&mutex);
    }
}
int main()
{
    pthread_t rtid[5], wtid[5];
    sem_init(&b, 0, 1); // remove this while using mutex
    sem_init(&r, 0, 5);
    for (i = 0; i < 5; i++)
    {
        pthread_create(&wtid[i], NULL, writer, NULL);
        pthread_create(&rtid[i], NULL, reader, NULL);
    }
    for (i = 0; i < 5; i++)
    {
        pthread_join(wtid[i], NULL);
        pthread_join(rtid[i], NULL);
    }
}