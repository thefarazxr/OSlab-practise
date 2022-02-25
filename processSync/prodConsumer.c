#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t b; // pthread_mutex_t mutex;
sem_t empty, full;
int buf = 0;
void *prod()
{
    while (1)
    {
        sem_wait(&empty);
        sem_wait(&b); // pthread_mutex_lock(&mutex);
        buf++;
        printf("Produced buf = %d\n", buf);
        sleep(1);
        sem_post(&b); // pthread_mutex_unlock(&mutex);
        sem_post(&full);
        if (buf == 5)
            sleep(60);
    }
}
void *cons()
{
    while (1)
    {
        sleep(5);
        sem_wait(&full);
        sem_wait(&b); // pthread_mutex_lock(&mutex);
        buf--;
        printf("Consumed buf = %d\n", buf);
        sleep(1);
        sem_post(&b); // pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

void main()
{
    pthread_t p, c;
    sem_init(&empty, 0, 5); // Here we considered buffer size=5 so 5 are Empty slots intially
    sem_init(&full, -5, 0); // intially 0 are full slots. *****  -5 idk whhy we kept!

    sem_init(&b, 0, 1); // NOTE:: line to be removed when MUTEX is used along with semaphore

    // This semaphore variable 'b' is used to achieve mutual exclusion between processes.
    // By using this variable, either Producer or Consumer will be allowed to use or access the shared buffer at a particular time.
    // This variable is set to 1 initially.

    pthread_create(&p, NULL, prod, NULL);
    pthread_create(&c, NULL, cons, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
}
