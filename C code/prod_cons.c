// Solve the classical producer consumer problem. Consider the buffer is bounded. Create
//  at least 3 producers and 3 consumers.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define buffer_size 10
sem_t empty, ful, mutex;
int nextproduced = 0;
int nextconsumed =0;
int buffer[buffer_size];
int in =0;
int out=0;

void* prod(void* a)
{
    

    while (1)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        
        nextproduced = nextproduced +1;
        buffer[in] = nextproduced;
        in = (in+1) % buffer_size ;

        printf("\nProducer-%d produces item---%d\n",(long)a,nextproduced);

        sem_post(&mutex);
        sem_post(&empty);

        sleep(1); // Simulate time taken to produce

    }
    return NULL;
}
void* cons(void* a)
{
    
    while(1)
    {
        sem_wait(&ful);
        sem_wait(&mutex);

        nextconsumed = buffer[out];
        out = (out+1) % buffer_size;

        printf("\nConsumer-%d consumed--%d\n",(long)a,nextconsumed);

        sem_post(&mutex);
        sem_post(&ful);

        sleep(1);
        

    }
    return NULL;
}
int main()
{
    int p;
    printf("Enter producer P : ");
    scanf("%d",&p);

    int c;
    printf("Enter Consumer C : ");
    scanf("%d",&c);

    pthread_t t1[p],t2[p];

    sem_init(&empty, 0, buffer_size);
    sem_init(&ful, 0, 0);
    sem_init(&mutex, 0, 1);  // value should be 1
    for(long i=0 ; i<p; i++)
    {
        pthread_create(&t1[i],NULL,prod, (void*) i);
    }
    for(long i=0 ; i<c; i++)
    {
        pthread_create(&t2[i],NULL,cons, (void*) i);
    }
    for(long i=0 ; i<p; i++)
    {
        pthread_join(t1[i],NULL);
    }
    for(long i=0 ; i<c; i++)
    {
        pthread_join(t2[i],NULL);
    }
    

    sem_destroy(&empty);
    sem_destroy(&ful);
    sem_destroy(&mutex);

}

