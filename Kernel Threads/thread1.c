#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/time.h>
#include <linux/timer.h>
static struct task_struct *T1, *T2;
static int thread_fn1(void *unused)
{
	int a,b,res,var;
	struct timeval t0, t1;
	do_gettimeofday(&t0);
	var = 10;
	printk("We are now inside T1!\n");
	a=10;
	b=40;
	res=a+b;
	printk("Addition in Thread 1\n");
	printk("Result is %d\n", res);
	do_gettimeofday(&t1);
	printk("T1 took %ld seconds and %ld micro seconds to execute\n",(t1.tv_sec-t0.tv_sec),(t1.tv_usec-t0.tv_usec));
	while(!kthread_should_stop())
    	schedule();
	return var;
}
static int thread_fn2(void *unused)
{
	int a,b,res1,var;
	struct timeval t0, t1;
	do_gettimeofday(&t0);
	printk("We are now inside T2!\n");
	printk("Multiplication in Thread 2\n");
	var=11;
	a=10;
	b=40;
	res1=a*b;
	printk("Result %d\n", res1);
	do_gettimeofday(&t1);
	printk("T2 took %ld seconds and %ld micro seconds to execute\n",(t1.tv_sec-t0.tv_sec),(t1.tv_usec-t0.tv_usec));
	while(!kthread_should_stop())
		schedule();
	return var;
}
int thread_init (void)
{
	struct timeval t0, t1;
	printk("Inside init\n");
	do_gettimeofday(&t0);
	T1 = kthread_create(thread_fn1,NULL,"T1");
	do_gettimeofday(&t1);
	printk("T1 took %ld seconds and %ld micro seconds to create\n",(t1.tv_sec-t0.tv_sec),(t1.tv_usec-t0.tv_usec));
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