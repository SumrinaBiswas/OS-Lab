// Solve the classical dining philosophers(5 philosophers) problem
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define n 5

//sem_t chop[n]; // dynamically size is not accepted, global variable is needed
//sem_t* chop;   // in this way dynamically size is allloed
sem_t chop[n];


void* philo(void* a)
{
    long id = (long)a;            // this is must for semaphore value
    
    while(1)
    {
        sem_wait(&chop[id]);    //  // Wait for left chopstick
        sem_wait(&chop[(id+1)%n]);   // Wait for right chopstick

        printf("\nPhilo--%d eating with %dand%d\n",id,id,((id+1)%n));

        sem_post(&chop[id]);
        sem_post(&chop[(id+1)%n]);

        printf("\nPhilo--%d thinking\n ",(long)a);

        sleep(1);
    }
    return NULL;
}
int main()
{

    for(long i=0;i<n;i++)
    {
        sem_init(&chop[i],0,1);
    }
    pthread_t philosopher[n];

    for(long i=0;i<n;i++)
    {
        pthread_create(&philosopher[i],NULL,philo,(void*) i);
    }
    for(long i=0;i<n;i++)
    {
        pthread_join(philosopher[i],NULL);
    }

    for(long i=0;i<n;i++)
    {
        sem_destroy(&chop[i]);
    }
    
}