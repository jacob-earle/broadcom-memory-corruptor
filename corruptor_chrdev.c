#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jacob Earle");
MODULE_DESCRIPTION("Registers a character device to control corruption via Broadcom controller.");
MODULE_VERSION("0.01");

#define DEVICE_NAME "corruptor"
static int major_number;
static ssize_t dev_write(struct file * f, const char * s, size_t size, loff_t * off);

static struct file_operations fops =
{
	.write = dev_write,
};

static ssize_t dev_write(struct file * f, const char * s, size_t size, loff_t * off){
	return 0;
}

static int __init my_init(void) {
 printk(KERN_INFO "Creating character device.\n");
 major_number = register_chrdev(0, DEVICE_NAME, &fops);
	if(major_number<0){
		printk(KERN_INFO "Failed to register character device.");
        unregister_chrdev(major_number, DEVICE_NAME);
	}
 return 0;
}
static void __exit my_exit(void) {
 printk(KERN_INFO "Dropping character device.\n");
 unregister_chrdev(major_number, DEVICE_NAME);
}
module_init(my_init);
module_exit(my_exit);
