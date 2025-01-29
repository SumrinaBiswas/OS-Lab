//  b) Solve the classical reader writer problem. Create 5 readers and 2 writers then
//  synchronize it.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

sem_t wrt, mutex;
int readcount = 0;
int sharedata = 0;

void* reader(void* a)
{
    while(1)
    {
        sem_wait(&mutex);
        readcount++;
        if(readcount == 1)
        {
            sem_wait(&wrt);
        }
        sem_post(&mutex);

        //Reading operation
        printf("\nReader--%d reads data--%d\n",(long)a,sharedata);

        sem_wait(&mutex);
        readcount--;
        if(readcount == 0)
        {
            sem_post(&wrt);
        }
        sem_post(&mutex);

        sleep(1);
    }
    //return NULL;
}
void* writer(void* a)
{
    while(1)
    {
        sem_wait(&wrt);
        // write operation
        sharedata++;
        printf("\nWriter--%d writes data--%d\n",(long)a,sharedata);
        sem_post(&wrt);

        sleep(1);  
    }
    //return NULL;
}
int main()
{
    int p;
    printf("Enter Reader R : ");
    scanf("%d",&p);
    int c;
    printf("Enter Writer W : ");
    scanf("%d",&c);
    
    pthread_t read[p],write[c];  // thread for reader and writer

    sem_init(&wrt,0,1);
    sem_init(&mutex,0,1);

    for(long i=0; i<p; i++)
    {
        pthread_create(&read[i],NULL,reader,(void*) i);
    }
    for(long i=0; i<c; i++)
    {
        pthread_create(&write[i],NULL,writer,(void*) i);
    }
    for(long i=0; i<p; i++)
    {
        pthread_join(read[i],NULL);
    }
    for(long i=0; i<c; i++)
    {
        pthread_join(write[i],NULL);
    }
    sem_destroy(&wrt);
    sem_destroy(&mutex);
}