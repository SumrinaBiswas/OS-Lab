//  Write a C program that will create a child process using the fork() system call. Draw the
//  process tree by generating different child process
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid1;
    pid_t pid2;
    pid_t pid3;

    pid1 = fork();
    if(pid1==0)
    {
        printf("\nChild process-1 PID : %d\n",getpid());
        printf("\nParent process-1 PID : %d\n",getppid());

        // inside Child-1
        pid2 = fork();
        if(pid2==0)
        {
            printf("\n\nChild process-2 PID : %d",getpid());
            printf("\nParent process-2 PID : %d",getppid());

                pid3 = fork();
                if(pid3==0)
                {
                    printf("\n\nChild process-3 PID : %d\n",getpid());
                    printf("\nParent process-3 PID : %d\n",getppid());
                }
                else
                {
                    wait(NULL); // / Wait for Child 2 to finish
                    // printf("\nParent process-3 PID : %d",getpid());
                    // printf("\nProcess-3 PID : %d",getppid());
                }
        }
        else
        {
            wait(NULL);
            // printf("\nParent process-2 PID : %d",getpid());
            // printf("\nProcess-2 PID : %d",getppid());
        }
    }
    else
    {
        printf("\nParent process-1 PID : %d\n",getpid());
        printf("\nProcess-1 PID : %d\n",getppid());
    }

    

    
}