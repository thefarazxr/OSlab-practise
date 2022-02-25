// using pthread_self() get current thread id
#include <pthread.h>
#include <stdio.h>
int a, b;         // global variables
pthread_t tid[2]; // global threads to make it accessible to the thread_function too

void *f() // this will access two threads tid[0],tid[1] we make use of pthread_self() to match the current thread and proceed for respective Operation.
{
    pthread_t id = pthread_self(); // using pthread_self() get current thread id
    if (pthread_equal(id, tid[0]))
        printf("Sum=%d\n", a + b);
    if (pthread_equal(id, tid[1]))
        printf("Difference=%d\n", a - b);
}

void main()
{
    int i;
    printf("\nMain Thread");
    printf("\nEnter 2 numbers");
    scanf("%d%d", &a, &b);
    for (i = 0; i < 2; i++)
        pthread_create(&tid[i], NULL, f, NULL);
    for (i = 0; i < 2; i++)
        pthread_join(tid[i], NULL);
}