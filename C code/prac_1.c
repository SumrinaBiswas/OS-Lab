// Dining
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>
#include <string.h>

// #define MAX 5

// sem_t chop[MAX];

// void* dining(void* a)
// {
//     int id = (long)a;
//     while(1)
//     {
//         sem_wait(&chop[id]);
//         sem_wait(&chop[(id+1)%5]);
//         printf("\nPhilosopher--%d eats with %d and %d\n",(long)a,id,(id+1)%5);
//         sem_post(&chop[id]);
//         sem_post(&chop[(id+1)%5]);
//         printf("\nPhilosopher--%d thinking\n",(long)a);

//         sleep(1);
//     }
//     return NULL;
// }
// int main()
// {
//     pthread_t t[MAX];

//     for(long i=1; i<=MAX; i++)
//     {
//         sem_init(&chop[i],0,1);
//     }

//     for(long i=1; i<=MAX; i++)
//     {
//         pthread_create(&t[i],NULL,dining,(void*)i);
//     }
//     for(long i=1; i<=3; i++)
//     {
//         pthread_join(t[i],NULL);
//     }
//     for(long i=1; i<=MAX; i++)
//     {
//         sem_destroy(&chop[i]);
//     }
// }


// reader writer

// sem_t wrt,mutex;
// int readcount=0;
// int sharedata=0;

// void* reader(void* a)
// {
//     while(1)
//     {
//         sem_wait(&mutex);

//         readcount++;
//         if(readcount ==1 )
//         {
//             sem_wait(&wrt);
//         }
//         sem_post(&mutex);

//         printf("\nReader--%d reads--%d\n",(long)a,sharedata);

//         sem_wait(&mutex);

//         readcount--;
//         if(readcount == 0)
//             sem_post(&wrt);
//         sem_post(&mutex);
//         sleep(1);
//     }
//     return NULL;
// }
// void* writer(void* a)
// {
//     while(1)
//     {
//         sem_wait(&wrt);
//             sharedata++;
//             printf("\nWriter--%d writes---%d\n",(long)a,sharedata);
//         sem_post(&wrt);
//         sleep(1);
//     }
// }
// int main()
// {
//     int r,c;
//     printf("Reader no : ");
//     scanf("%d",&r);
//     printf("Writer no : ");
//     scanf("%d",&c);

//     pthread_t readers[r],writers[c];

//     sem_init(&wrt,0,1);
//     sem_init(&mutex,0,1);

//     for(long i=1; i<=r;i++)
//     {
//         pthread_create(&readers[i],NULL,reader,(void*) i);
//     }
//     for(long i=1; i<=c;i++)
//     {
//         pthread_create(&writers[i],NULL,writer,(void*) i);
//     }
//     for(long i=1; i<=r;i++)
//     {
//         pthread_join(readers[i],NULL);
//     }
//     for(long i=1; i<=c;i++)
//     {
//         pthread_join(writers[i],NULL);
//     }

//     sem_destroy(&wrt);
//     sem_destroy(&mutex);

//     return 0;
// }

//producer consumer
#define max 50
sem_t empty,full,mutex;
int in=0;
int out=0;
int buffer[max];
int nextp=0;
int nextc=0;

void* prod(void* a)
{
    while(1)
    {
        sem_wait(&empty);
        sem_wait(&mutex);

        nextp++;
        buffer[in] = nextp;
        in = (in+1) % max;
        printf("\nProducer--%d produces--%d\n",(long)a,nextp);

        sem_post(&mutex);
        sem_wait(&empty);

        sleep(1);
    }
    return NULL;
}
void* cons(void* a)
{
    while(1)
    {
        sem_wait(&full);
        sem_wait(&mutex);

        nextc = buffer[out] ;
        out = (out+1) % max;
       printf("\nConsumer--%d consumes--%d\n",(long)a,nextc);

        sem_post(&mutex);
        sem_wait(&full);

        sleep(1);
    }
    return NULL;
}
int main()
{
    int p,c;
    printf("Enter producers : ");
    scanf("%d",&p);
    printf("Enter consumers : ");
    scanf("%d",&c);
    pthread_t p1[p], c1[p];

    sem_init(&empty,0,max);
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);

    for(long i=1; i<=p;i++)
    {
        pthread_create(&p1[i],NULL,prod,(void*) i);
    }
    for(long i=1; i<=c;i++)
    {
        pthread_create(&c1[i],NULL,cons,(void*) i);
    }
    for(long i=1; i<=p;i++)
    {
        pthread_join(p1[i],NULL);
    }
    for(long i=1; i<=c;i++)
    {
        pthread_join(c1[i],NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&mutex);
    sem_destroy(&full);

    return 0;
}