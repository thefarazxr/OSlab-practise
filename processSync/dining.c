#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
// Semaphore is simply an integer variable that is shared between threads.
// This variable is used to solve the critical section problem and to achieve process synchronization in the multiprocessing environment.
sem_t chopstick[5];
pthread_t philosopher[5];

void *runner(void *arg)
{
    int i = *(int *)arg; // REMEMBER this!
    printf("Philosopher %d is thinking \n", i);
    sleep(2);
    sem_wait(&chopstick[i]);
    sem_wait(&chopstick[(i + 1) % 5]);
    printf("philosopher %d is eating \n", i);
    sleep(3);
    sem_post(&chopstick[i]);
    sem_post(&chopstick[(i + 1) % 5]);
    printf("Philosopher %d finished eating \n", i);
}

int main()
{
    int i;
    for (i = 0; i < 5; i++)
        sem_init(&chopstick[i], 0, 1);
    // The 1st param is the pointer to the declared semaphore.
    // The 2nd param is pshared. If it is zero, the semaphore is shared between threads; else it is shared between processes. In our case it is zero meaning it is shared between threads.
    // The 3rd param  is value with which the semaphore is initialized.

    for (i = 0; i < 5; i++)
    {
        pthread_create(&philosopher[i], NULL, runner, &i);
        sleep(1);
    }
    for (i = 0; i < 5; i++)
        pthread_join(philosopher[i], NULL);
}
