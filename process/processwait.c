#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
	pid_t c_pid, pid;
	int status;
	c_pid = fork();
	if(c_pid == 0) {
		pid = getpid();
		printf("Child : %d\n", c_pid);
		printf("Child sleeping for 2-seconds, then exiting with status 12\n", sleep(2));
		exit(12);
	}
	else if(c_pid > 0)
	{
		pid = wait(&status);
		if(WIFEXITED(status))
		{
			printf("Parent: Child exited with status: %d\n", WEXITSTATUS(status));
		}
	}
	else if(c_pid == -1)
	{
		perror("Fork Error");
		exit(0);
	}
	return 0;
}