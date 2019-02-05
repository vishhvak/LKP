/* LKM to print "Hello, World!" to the kernel log */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Vishhvak");
MODULE_DESCRIPTION("Hello World");

static int __init hello_init(void) {
	printk(KERN_INFO "Hello, world!\n");
	return 0;
}

static void __exit hello_cleanup(void) {
	printk(KERN_INFO "Cleaning up module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);