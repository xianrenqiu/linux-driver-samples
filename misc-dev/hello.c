#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <asm/uaccess.h>
#include "hello.h"

static char hello_data[100];

static int hello_read(struct file * file, char *data)
{
    printk("%s [#%d]\n",__func__,__LINE__);
    if (unlikely(copy_to_user(data, hello_data, strlen(hello_data)))){
                printk("copy_to_user faild\n");
                return -EFAULT;
        }
      
    return 0;  
}

static int hello_write(struct file * file, char *data)
{
    printk("%s [#%d]\n",__func__,__LINE__);
    if (unlikely(copy_from_user(hello_data, data, strlen(data)))){
                printk("copy_from_user faild\n");
                return -EFAULT;
        }    

    return 0;   
}

static int hello_open(struct inode *inode, struct file *filp)
{
    printk("%s [#%d]\n",__func__,__LINE__);
    return 0;
}

static int hello_release(struct inode *inode, struct file *filp)
{
    printk("%s [#%d]\n",__func__,__LINE__);
    return 0;
}

static long hello_ioctl(struct file *filp, unsigned int cmd, unsigned long arg_)
{
    void __user *arg = (void __user *)arg_;

    int ret, fd;

    switch(cmd) {
    case DATA_WRITE:
        hello_write(filp, arg);
    break;

    case DATA_READ:
        hello_read(filp, arg);
    break;    

    default:
        return -EINVAL;
    }
    return 0;
}

static const struct file_operations hello_fops =
{
    .owner = THIS_MODULE,
    .open = hello_open,
    .release = hello_release,
    .unlocked_ioctl = hello_ioctl,
};

static struct miscdevice hello_dev =
{
    MISC_DYNAMIC_MINOR,
    "hello",
    &hello_fops,
};

static int __init hello_init(void)
{
    int ret;
    /*
    * Create the "hello" device in the /sys/class/misc directory.
    * Udev will automatically create the /dev/hello device using
    * the default rules.
    */
    ret = misc_register(&hello_dev);
    if (ret != 0)
    {
        printk(KERN_ERR "register \"hello\" misc device failed.\n");
    }
    else
    {
        printk(KERN_INFO "register \"hello\" misc device success.\n");
    }

    return ret;
}
module_init(hello_init);

static void __exit hello_exit(void)
{
    misc_deregister(&hello_dev);
    printk(KERN_INFO "deregister \"Hello World!\" misc device...\n");
}
module_exit(hello_exit);

MODULE_LICENSE("Dual BSD/GPL");