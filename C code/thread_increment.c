//  b) A variable count is shared by 3 threads. Each thread will increment the variable. Write a C
//  program to synchronize the threads

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>
int c=0;
sem_t sem1;

void* increment(void* a)
{
    for(int i=0 ;i<5; i++)
    {
        c++;
    }
    printf("\nThread--%d\nValue of c : %d",(long)a,c);
    sem_post(&sem1);
    return NULL;
}
int main()
{
    pthread_t t[3];

    sem_init(&sem1,0,0);
    
    for(long i=1; i<=3; i++)
    {
        pthread_create(&t[i],NULL,increment,(void*)i);
    }
    for(long i=1; i<=3; i++)
    {
        pthread_join(t[i],NULL);;
    }
    
    sem_destroy(&sem1);
    return 0;
}