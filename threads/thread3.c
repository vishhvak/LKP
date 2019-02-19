#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *print_message(void *ptr);

void main(){
	pthread_t thread1, thread2;
	const char *message1="Thread1";
	const char *message2="Thread2";
	int t1, t2;
	
	//Create independent threads which will execute Function	
	t1 = pthread_create(&thread1, NULL, print_messsage, (void*)message1);
	if(t1){
		fprintf(stderr, "Error - pthread_create() return code: %d\n",t1);
		exit(EXIT_FAILURE);
	}
	t2 = pthread_create(&thread1, NULL, print_messsage, (void*)message2);
	if(t2){
		fprintf(stderr, "Error - pthread_create() return code: %d\n",t2);
		exit(EXIT_FAILURE);
	}
	printf("pthread_create() for thread 1 returns : %d\n", t1):
	printf("pthread_create() for thread 2 returns : %d\n", t2):
}

void *print_message(void *ptr){
	char *message;
	message = (char *)ptr;
	printf("%s\n",message);
}