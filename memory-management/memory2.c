#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/gfp.h>
#include <linux/mm.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

void memory_allocation(void) 
{
	unsigned long page;
	page = __get_free_page(GFP_KERNEL);
	printk("Location of page: %p\n", (void *) page);
	printk("Location of heap: %p\n", (void *) kmalloc(sizeof(page),GFP_KERNEL));
}

static int __init memory_init(void)
{
 printk("Initialising module\n");
 memory_allocation();
 return 0;
}
static void __exit memory_cleanup(void)
{
 printk(KERN_INFO "Cleaning up module.\n");
}

module_init(memory_init);
module_exit(memory_cleanup);