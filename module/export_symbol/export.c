#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

/* 导出符号 */
EXPORT_SYMBOL_GPL(add);
EXPORT_SYMBOL_GPL(sub);