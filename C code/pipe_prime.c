//  Write a C program where parent process send a number to child process using PIPE and
//  child process compute whether that number is a prime number or not

#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    int num;
    int res[10];
    int pipefds[2];
    int c;

    if(pipe(pipefds)== -1)
    {
        printf("\nfailure of creation of pipe");
    }
    pid = fork();

    if(pid == 0)
    {
        printf("\nThis is child process");

        close(pipefds[1]);
        read(pipefds[0], &num, sizeof(num));

        if(num == 2)
        {
            printf("Prime %d",num);
        }
        else
        {
            for (int i = 2; i < num; i++ )
            {
                if(num % i == 0)
                {
                    c = 0;
                    break;
                }
                else{
                    c=1;
                }
            }
            if(c==0)
                printf("\nNot prime : %d",num);
            else
                printf("\nPrime %d",num);
        
        }
        close(pipefds[0]);

    }
    else
    {
        printf("\nThis is parent process");

        close(pipefds[0]);

        printf("\nEnter number : ");
        scanf("%d",&num);

        write(pipefds[1], &num, sizeof(num));

       
        close(pipefds[1]);
        wait(NULL);

    }
}