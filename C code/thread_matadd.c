

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1,sem2;
int mat1[100][100], mat2[100][100], add[100][100];
int r1,c1,r2,c2;

void* read_mat1()
{
    printf("\nEnter row for mat-1: ");
    scanf("%d",&r1);
    printf("\nEnter col for mat-1: ");
    scanf("%d",&c1);

    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
        {
            printf("Enter elem-%d-row : ",i);
            scanf("%d",&mat1[i][j]);
        }
    }
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
        {
            printf("%d\t",mat1[i][j]);
        
        }
        printf("\n");
    }
    sem_post(&sem1);
    return NULL;
}
void* read_mat2()
{
    sem_wait(&sem1);
    printf("\nEnter row for mat-2 : ");
    scanf("%d",&r2);
    printf("\nEnter col for mat-2 : ");
    scanf("%d",&c2);

    for(int i=0; i<r2; i++)
    {
        for(int j=0; j<c2; j++)
        {
            printf("Enter elem-%d-row : ",i);
            scanf("%d",&mat2[i][j]);
        }
    }
    for(int i=0; i<r2; i++)
    {
        for(int j=0; j<c2; j++)
        {
            printf("%d\t",mat2[i][j]);
        
        }
        printf("\n");
    }
    sem_post(&sem2);
    return NULL;
}
void* addition()
{
    sem_wait(&sem2);

    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
        {
            add[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printf("\nAddition of matrices : \n");
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
        {
            printf("%d\t",add[i][j]);
        
        }
        printf("\n");
    }
    
    return NULL;
}
int main()
{
    pthread_t t1,t2,t3;

    sem_init(&sem1,0,0);
    sem_init(&sem2,0,0);

    pthread_create(&t1,NULL,read_mat1,NULL);
    pthread_create(&t2,NULL,read_mat2,NULL);
    pthread_create(&t3,NULL,addition,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);

    sem_destroy(&sem1);
    sem_destroy(&sem2);
}