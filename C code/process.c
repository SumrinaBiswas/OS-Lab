#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid==0)
	{
		printf("\nChild process : %d",getpid());
		printf("\nParent process : %d",getppid());
	}
	else{
		wait(NULL);
		printf("\nProcess process : %d",getppid());
		printf("\nParent process : %d\n",getpid());
	}
	return 0;
}