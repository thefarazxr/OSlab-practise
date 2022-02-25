#include <stdio.h>
#include <pthread.h>
int a, b; // keep them as GLOBAL variables
void *add()
{
    printf("Sum of two numbers = %d\n", a + b);
}
void *sub()
{
    printf("Difference of two numbers = %d\n", a - b);
}

int main()
{
    printf("enter a,b");
    scanf("%d%d", &a, &b);
    pthread_t tid1, tid2;
    printf("\n I am the main process");
    pthread_create(&tid1, NULL, add, NULL);
    pthread_create(&tid2, NULL, sub, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("\n Back to main process \n");
}
