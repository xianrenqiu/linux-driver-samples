#include <linux/init.h>
#include <linux/module.h>

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello world enter\n");
	return 0;
}
module_init(hello_init);

static int __exit hello_exit(void)
{
	printk(KERN_INFO "Hello world exit\n");
	return 0;
}
module_exit(hello_exit);

MODULE_LICENSE("Dual BSD/GPL");