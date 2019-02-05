#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
	pid_t c_pid;
	c_pid = fork();
	if(c_pid == 0) {
		printf("I am the child : %d\n", c_pid);
		if(c_pid > 0) {
			printf("I am the parent: %d\n", c_pid);
		}
	}
	else if(c_pid > 0)
	{
		printf("I am the parent: %d\n", c_pid);
	}
	else if(c_pid == -1)
	{
		perror("Fork Error");
		exit(0);
	}
	return 0;
}