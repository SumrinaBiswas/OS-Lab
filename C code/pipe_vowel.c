#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main()
{
    int fd[2];
    char str[100];
    pid_t child;
    int vowel = 0;
    int conso = 0;

    if(pipe(fd) == -1)
    {
        printf("Failure of creating pipe");
    }
    child = fork();

    if(child == 0)
    {
        printf("\nThis is Child process\n");
        close(fd[1]);
        read(fd[0], &str, sizeof(str));

        for(int i=0; i< strlen(str); i++)
        {
            if(str[i]=='A' || str[i]=='a' || str[i]=='E' ||str[i]=='e' || str[i]=='I' || str[i]=='i' || str[i]=='O' || str[i]=='o' || str[i]=='U' || str[i]=='u' )
            {
                vowel++; 
                //printf("\nVowel-%d : %s",i,str[i]);  // not executable
            }
            else
            {
                //printf("\nConso-%d : %s",i,str[i]);
                conso++;
            }
                
        }
        printf("\nVowel = %d\nConsonant = %d\n",vowel,conso);

        close(fd[0]);
    }
    else{
        printf("\nThis is Parent process\n");
        close(fd[0]);
        printf("Enter String : ");
        scanf("%s",&str);

        write(fd[1], &str, strlen(str)+1);
        close(fd[1]);
        printf("\nFinish parent");
        wait(NULL);
    }
    return 0;
} 