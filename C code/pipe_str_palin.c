//  b) Write a C program to create a child process. Parent process send a string to child
//  process using PIPE then child process will check the string is palindrome or not.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>
#include <string.h>

int fd[2];
pid_t pid;
char str[50];
char gtr[50];

int main()
{
    if(pipe(fd) < 0)
    {
        printf("Pipe creation failed");
    }
    pid = fork();

    if(pid==0)
    {
        close(fd[1]);
        read(fd[0],str,sizeof(str));

        int len = strlen(str);

        for(int i=0; i< strlen(str); i++)
        {
            gtr[i]=str[(strlen(str) - 1 - i)];
        }
        // gtr[len] = '\0'; // Null-terminate the reversed string
        if(strcmp(str,gtr) == 0)
        {
            printf("Palindrome : %s",str);
        }
        else
        {
            printf("Not Palindrome : %s",str);
        }

        close(fd[0]);

    }
    else
    {
        close(fd[0]);

        printf("Enter String : ");
        scanf("%s",&str);
        write(fd[1],str,strlen(str)+1);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}
