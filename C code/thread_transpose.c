// b) Write a C program to create two threads. 1st thread will take input of a matrix and 2nd
//  thread will perform Transpose of the matrix i.e after 1st thread, 2nd thread will start
//  execution

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>

sem_t sem1,sem2;
int mat1[100][100];
int mat2[100][100];
int r,c;
void* read_mat()
{
    printf("\nEnter rows and cols :");
    scanf("%d%d",&r,&c);

    for(int i =0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("\nEnter row--%d : ",i);
            scanf("%d",&mat1[i][j]);
        }
    }
    for(int i =0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("%d\t",mat1[i][j]);
        }
        printf("\n");
    }
    sem_post(&sem1);
    return NULL;
}
void* result()
{
    sem_wait(&sem1);

    for(int i =0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            mat2[i][j] = mat1[j][i];
        }
    }
    printf("\nTranspose mat : \n");
    for(int i =0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("%d\t",mat2[i][j]);
        }
        printf("\n");
    }
    return NULL;
}
int main()
{
    pthread_t t1,t2;

    sem_init(&sem1,0,0);

    pthread_create(&t1,NULL,read_mat,NULL);
    pthread_create(&t2,NULL,result,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    sem_destroy(&sem1);
    return 0;
}