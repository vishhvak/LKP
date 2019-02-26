#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <dirent.h>

void cmdcopy() {
	struct timeval t0, t1;
	char* command = "cp a.txt y.txt";
	gettimeofday(&t0, NULL);
	system(command);
	gettimeofday(&t1, NULL);
	printf("\nCopy using command cp took %ld seconds and %ld micro seconds to execute\n\n",(t1.tv_sec-t0.tv_sec),(t1.tv_usec-t0.tv_usec));
}

void copy() {
	struct timeval t0, t1;
	gettimeofday(&t0, NULL);
	FILE *fp, *op;
	fp = fopen("a.txt", "r");
	op = fopen("y1.txt", "w");
	char c;
	c = fgetc(fp);
	while(c != EOF) {
		fputc(c, op);
		c = fgetc(fp);
	}
	fclose(op);
	fclose(fp);
	gettimeofday(&t1, NULL);
	printf("\nCopy using procedure took %ld seconds and %ld micro seconds to execute\n\n",(t1.tv_sec-t0.tv_sec),(t1.tv_usec-t0.tv_usec));
}

void cat() {
	struct timeval t0, t1;
	gettimeofday(&t0, NULL);
	FILE *fp;
	fp = fopen("a.txt", "r");
	char c;
	c = fgetc(fp);
	while(c != EOF) {
		printf("%c",c);
		c = fgetc(fp);
	}
	fclose(fp);
	gettimeofday(&t1, NULL);
	printf("\nThe cat procedure took %ld seconds and %ld micro seconds to execute\n\n",(t1.tv_sec-t0.tv_sec),(t1.tv_usec-t0.tv_usec));

}

void cmdcat() {
	struct timeval t0, t1;
	char* command = "cat a.txt";
	gettimeofday(&t0, NULL);
	system(command);
	gettimeofday(&t1, NULL);
	printf("\nThe cat command took %ld seconds and %ld micro seconds to execute\n\n",(t1.tv_sec-t0.tv_sec),(t1.tv_usec-t0.tv_usec));
}

void ls() {
	struct timeval t0, t1;
	gettimeofday(&t0, NULL);
	DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    gettimeofday(&t1, NULL);
	printf("\nThe ls procedure took %ld seconds and %ld micro seconds to execute\n\n",(t1.tv_sec-t0.tv_sec),(t1.tv_usec-t0.tv_usec));

}

void cmdls() {
	struct timeval t0, t1;
	char* command = "ls";
	printf("\n");
	gettimeofday(&t0, NULL);
	system(command);
	gettimeofday(&t1, NULL);
	printf("\nThe ls command took %ld seconds and %ld micro seconds to execute\n\n",(t1.tv_sec-t0.tv_sec),(t1.tv_usec-t0.tv_usec));

}

void main()
{
	// System Call/Command
	copy();
	cmdcopy();
	cat();
	cmdcat();
	ls();
	cmdls();
}
