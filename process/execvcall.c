#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	char* ls_args[] = { "./add", NULL};
	printf("add.c\n");
	execv(ls_args[0], ls_args);
	perror("execv");
	return 0;
}