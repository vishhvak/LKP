#include<linux/gfp.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/mm.h>

MODULE_LICENSE("GPL");

void binbuddyfree(void) 
{
	unsigned long page = __get_free_pages(GFP_KERNEL,10);
	signed short n;
	signed short m=6; //number of pages each process requires
	n = 10; //number of pages allocated
	memset((void *)page,'0',sizeof(page));
	if(!page)
		printk("Return error\n");
	else
		printk("Success %p\n",(void *) page);
	while(n>=m)
		n = n/2;
	if(n<m)
		n = n*2;
	__free_pages((void*) page, n);
	printk("The no. of pages freed are %hi\n", n);
}
static int memory_init(void) 
{
	printk("Initialising module\n");
	binbuddyfree();
	return 0;
}
static void memory_cleanup(void) 
{
	printk("Cleaning up module\n");
}
module_init(memory_init);
module_exit(memory_cleanup);