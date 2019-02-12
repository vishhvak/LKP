#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void stop(int signum) {
    printf("\nI have been put to sleep.\n");
}

void wakeup(int signum) {
    printf("\nI have been woken up after sleeping for 3 seconds.\n");
}

void killed(int signum) {
    printf("\nI have been killed.");
}

int main() {
	pid_t c_pid;
	c_pid = fork();
	if(c_pid == 0) {
		printf("I am the child : %d\n", c_pid);
		signal(SIGTSTP, stop);
        signal(SIGALRM, wakeup);
        alarm((usigned)3);
        signal(SIGKILL, killed); 
        while(1); 
	}
	else if(c_pid > 0)
	{
		printf("I am the parent: %d\n", c_pid);
        kill(c_pid, SIGTSTP);
        kill(c_pid, SIGCONT);
        kill(c_pid, SIGKILL);
	}
	else if(c_pid == -1)
	{
		perror("Fork Error");
		exit(0);
	}
	return 0;
}