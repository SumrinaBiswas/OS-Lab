// Write a C program to create a child process. Parent process send a string to child
//  process using PIPE then child process will calculate how many, alphabet, numeric and
//  special characters (#, &) are there?
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main()
{
    pid_t pid;
    int pipefds[2];
    char str[100];
    int alpha = 0;
    int num = 0;
    int spchar = 0;

    if (pipe(pipefds) == -1)
    {
        printf("\nfailure of creation of pipe");
    }
    pid = fork();
    if(pid == 0)
    {
        printf("\nThis is child process");
        close(pipefds[1]);
        read(pipefds[0], str, sizeof(str));

        for(int i=0; str[i] != '\0'; i++)
        {
            if(('A'<= str[i] && 'Z'>= str[i]) || ('a'<= str[i] && 'z'>= str[i]))
                alpha++;
            else if((str[i]>= '0' && str[i]<= '9'))
                num++;
            else
            {
                //printf("Sp char %s",str[i]);
                spchar++;
            }
                
        }
        printf("\nAlphabets : %d\nNumerics : %d\nSpecial char : %d",alpha,num,spchar);

        close(pipefds[0]);
    }
    else
    {
        printf("\nThis is parent process");

        close(pipefds[0]);

        printf("\nEnter String : ");
        scanf("%s",&str);

        write(pipefds[1], str, strlen(str)+1);

       
        close(pipefds[1]);
        wait(NULL);

    }
     
}