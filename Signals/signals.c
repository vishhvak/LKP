#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void stop(int signum) {
    printf("\nI have been put to sleep.\n");
}

void wakeup(int signum) {
    printf("\nI have been woken up after sleeping.\n");
}


int main() {
	pid_t c_pid;
	c_pid = fork();
	if(c_pid == 0) {
		printf("I am the child : %d\n", c_pid);
		signal(SIGTSTP, stop);
        signal(SIGALRM, wakeup);
        alarm((unsigned)3);
        signal(SIGKILL, SIG_IGN); 
        while(1); 
	}
	else if(c_pid > 0)
	{
		sleep(1);
		printf("I am the parent: %d\n", c_pid);
        kill(c_pid, SIGTSTP);
        sleep(1);
        kill(c_pid, SIGCONT);
        sleep(3);
        kill(c_pid, SIGKILL);
	}
	else if(c_pid == -1)
	{
		perror("Fork Error");
		exit(0);
	}
	return 0;
}