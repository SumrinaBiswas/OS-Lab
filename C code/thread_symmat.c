// Create two threads one thread will take the input of a matrix and 2nd thread will check
//  the matrix is symmetric or not

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1;
int r, c;
int mat1[100][100];
int f =0;

void* read_mat()
{
    printf("\nEnter row : ");
    scanf("%d",&r);
    printf("\nEnter col : ");
    scanf("%d",&c);

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("Enter elem-%d-row : ",i);
            scanf("%d",&mat1[i][j]);
        }
    }
    for(int i=0; i<r; i++)
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

void* sym()
{
    sem_wait(&sem1);

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(mat1[i][j] != mat1[j][i])
            {
                f = 0;
                break;
            }
            else{
                f++;
            }
        }
    }
    if(f==0)
    {
        printf("\nNot Symmetric");
    }
    else{
        printf("\nSymmetric");
    }

    return NULL;
}

int main()
{
    pthread_t t1,t2;

    sem_init(&sem1, 0, 0);

    pthread_create(&t1, NULL, read_mat, NULL);
    pthread_create(&t2, NULL, sym, NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    sem_destroy(&sem1);
    
}