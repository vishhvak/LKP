#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/gfp.h>
#include <linux/mm_types.h>

void pagealloc(void) {
	signed short count=0;
	unsigned long pages;
	while(count<1500) {
		pages= __get_free_pages(GFP_KERNEL, 1);
		if(!pages) {
			break;
		}
		count++;
	}
	printk("The no. of pages allocated are: %hi", count);
}

static int __init memory_init(void)
{
	pagealloc();
	return 0;
}
static void __exit memory_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
}

module_init(memory_init);
module_exit(memory_cleanup);