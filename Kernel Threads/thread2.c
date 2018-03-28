#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/time.h>
#include <linux/timer.h>
#include <linux/unistd.h>

static struct task_struct *T1, *T2;
static int thread_fn1(void *unused)
{
	int var;
	var=10;
	struct timeval t0, t1;
	do_gettimeofday(&t0);
	printk("We are now inside T1!\n");
	printk("System Call in Thread 1\n");
	schedule();
	do_gettimeofday(&t1);
	printk("System Call took %ld seconds and %ld micro seconds to execute\n",(t1.tv_sec-t0.tv_sec),(t1.tv_usec-t0.tv_usec));
	while(!kthread_should_stop())
    	schedule();
	return var;
}
int sub(int a, int b)
{
	return(a-b);
}
static int thread_fn2(void *unused)
{
	int a,b,res1,var;
	struct timeval t0, t1;
	do_gettimeofday(&t0);
	printk("We are now inside T2!\n");
	printk("Function to Subtract 2 numbers in Thread 2\n");
	var=11;
	a=10;
	b=40;
	res1=sub(a,b);
	printk("Result %d\n", res1);
	do_gettimeofday(&t1);
	printk("Function call took %ld seconds and %ld micro seconds to execute\n",(t1.tv_sec-t0.tv_sec),(t1.tv_usec-t0.tv_usec));
	while(!kthread_should_stop())
		schedule();
	return var;
}
int thread_init (void)
{
	printk("Inside Init\n");
	T1 = kthread_create(thread_fn1,NULL,"T1");
	if((T1))
	{
		printk("Yay! Created T1!\n");
		wake_up_process(T1);
	}
	T2 = kthread_create(thread_fn2, NULL, "T2");
	if((T2))
	{
		printk(KERN_INFO "Yay! Created T2!\n");
		wake_up_process(T2);
	}
	return 0;
}

void thread_cleanup(void)
{
	int ret;
	ret = kthread_stop(T1);
	if(!ret)
		printk("Aw, T1 stopped\n");
	ret = kthread_stop(T2);
	if(!ret)
		printk("Aw, T2 stopped\n");
}
MODULE_LICENSE("GPL");
module_init(thread_init);
module_exit(thread_cleanup);