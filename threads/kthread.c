#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/unistd.h>

static struct task_struct *T1, *T2;

int sub(int a, int b)
{
	return(a-b);
}

static int thread_fn(void *unused)
{
	int a,b,res1,var;
	printk("We are now inside T1!\n");
	printk("Function to Subtract 2 numbers in Thread 1\n");
	var=11;
	a=15;
	b=40;
	res1=sub(a,b);
	printk("Result %d\n", res1);
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
		printk("Created T1!\n");
		wake_up_process(T1);
	}
	return 0;
}

void thread_cleanup(void)
{
	int ret;
	ret = kthread_stop(T1);
	if(!ret)
		printk("T1 stopped\n");
}
MODULE_LICENSE("GPL");
module_init(thread_init);
module_exit(thread_cleanup);