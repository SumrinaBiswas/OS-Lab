//  b) Consider 3 threads running simultaneously. First thread1 read a number a. After that
//  thread2 reads a number b then thread3 will do addition of a and b. Synchronize it using
//  semaphore.

#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

int a,b,sum;
sem_t sem1,sem2;
void* read_a()
{
    printf("Enter a : ");
    scanf("%d",&a);
    sem_post(&sem1); //   Signal sem1 to allow thread 2 to proceed
    return NULL;
} 
void* read_b()
{
    sem_wait(&sem1);
    printf("Enter b : ");
    scanf("%d",&b);
    sem_post(&sem2); //   Signal sem2 to allow thread 2 to proceed
    return NULL;
}
void* add()
{
    sem_wait(&sem2);
    sum = a+b;
    printf("Sum is : %d",sum);
    return NULL;
    
}
int main()
{
    pthread_t t1,t2,t3;

    // Initialize
    sem_init(&sem1,0,0); // Sem : A pointer to the semaphore you want to initialize.  shared process : 0(semaphore shared b/w only one process)   initial value: 0(locked) 1(unlocked)
    sem_init(&sem2, 0, 0);

    //Create thread
    pthread_create(&t1, NULL, read_a, NULL);
    pthread_create(&t2, NULL, read_b, NULL);
    pthread_create(&t3, NULL, add, NULL);

    //join thread
    pthread_join(t1,NULL);   //All threads complete before the program exits.
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);

    // Destroy semaphores
    sem_destroy(&sem1);
    sem_destroy(&sem2);

    return 0;
}