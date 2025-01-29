//  b) Write a C program using fork() system call that generates the Fibonacci sequence in the
//  parent process and prime checking in the child process.
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
    int a = 0;
    int b = 1;

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

        printf("\nFibbonacci series : ");
        printf("%d\t%d",a,b);
        for(int i=2; i<num; i++)
        {
            int t = a+b;
            printf("\t%d",t);
            a=b;
            b=t;
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