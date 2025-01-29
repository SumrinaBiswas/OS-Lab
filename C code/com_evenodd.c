// //Write a C program where the parent process sends a number to child process using PIPE
//  and child process computes whether that number is an odd or even number

#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int pipefds[2]; // File descriptors for the pipe
    pid_t pid;
    char res[10];
    int num;
// Create the pipe
    if(pipe(pipefds) == -1)
    {
        printf("Pipe creation failed"); 
    }

    pid = fork(); // child process

    if(pid == -1)
        printf("\nFork failed");
    if(pid == 0)   // child process
    {
        printf("\nThis is child process");
        close(pipefds[1]); // close write end of pipe

        read(pipefds[0], &num, sizeof(num));

        if(num % 2 == 0)
            printf("\nEven %d",num);
        else
            printf("\nOdd %d",num);

        close(pipefds[0]); // close read end
    }
    else
    {
        printf("\nThis is Parent process");
        close(pipefds[0]); // close read end of pipe

        printf("\nEnter number : ");
        scanf("%d",&num);
        
        write(pipefds[1], &num, sizeof(num));


        close(pipefds[1]); // close read end

        wait(NULL);
    }
    return 0;
}