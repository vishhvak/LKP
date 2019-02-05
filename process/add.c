#include <stdio.h>
#include<unistd.h> 
int main()
{
	int a, b;
	printf("Enter two numbers one by one to sum.\n");
	scanf("%d", &a);
	scanf("%d", &b);
	int c = a+b;
	printf("Sum is %d", c);
	return 0;
}