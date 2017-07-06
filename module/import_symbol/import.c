#include <linux/init.h>
#include <linux/module.h>

/* 使用导出符号函数 */
extern int add(int, int);
extern int sub(int, int);

static int __init import_init(void)
{
	int rc = add(5, 6);
	printk(KERN_INFO "[import symbol] -> add(5, 6) = %d\n", rc);
	return 0;
}
module_init(import_init);

static int __exit import_exit(void)
{
	printk(KERN_INFO "import symbol exit\n");
	return 0;
}
module_exit(import_exit);

MODULE_LICENSE("Dual BSD/GPL");