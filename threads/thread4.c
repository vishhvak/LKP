#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
struct student {
    char name[10];
    int age;
    float gpa;
};
 
void* pt1(void* s1)
{
    struct student* s = s1;
    printf("\nThread 1 Function starting\n");
    printf("\nThis thread prints name and age of student passed\n");
    printf("Name is %s, Age is %d", s->name, s->age);
    printf("\nThread 1 Function done.");
    printf("\n");
    return NULL;
}

void* pt2(void* s2)
{
    struct student* s = s2;
    printf("\nThread 2 Function starting\n");
    printf("\nThis thread prints name and age of student passed\n");
    printf("GPA is %f", s->gpa);
    printf("\nThread 2 Function done.");
    printf("\n");
    return NULL;
}

int main()
{
    struct student *s1 = (struct student*)malloc(sizeof(struct student));
    strcpy(s1->name,"Vishhvak");
    s1->age = 20;
    s1->gpa = 8.0;
    pthread_t t1,t2;
    pthread_create(&t1,NULL, pt1, s1);
    pthread_join(t1,NULL);
    pthread_create(&t2,NULL, pt2, s1);
    pthread_join(t2,NULL);
    return 0;
}


