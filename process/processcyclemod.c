#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
	int pid, status;
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
		printf("Child sleeping for 2-seconds, then exiting with status 12\n", sleep(2));
		exit(12);
	}
	else if(pid > 0)
	{
		pid = wait(&status);
		if(WIFEXITED(status))
		{
			printf("Parent: Child exited with status: %d\n", WEXITSTATUS(status));
			printf("Parent process\n");
			printf("Process id = %d\n", getpid());
			exit(0);
		}

	}
	return 0;
}