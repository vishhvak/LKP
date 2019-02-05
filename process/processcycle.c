#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
	int pid;
	printf("Process related system calls\n");
	if((pid=fork())==-1) {
		perror("During fork\n");
		exit(0);
	}
	if(pid == 0)
	{
		printf("Child process\n");
		printf("Process id = %d\n", getpid());
		printf("Process id of parent = %d\n", getppid());
		exit(0);
	}
	else
	{
		printf("Parent process\n");
		printf("Process id = %d\n", getpid());
		printf("Process Id of parent = %d\n", getppid());
		exit(0);
	}
	return 0;
}