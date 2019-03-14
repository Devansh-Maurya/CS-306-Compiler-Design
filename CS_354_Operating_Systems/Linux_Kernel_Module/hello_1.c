#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gaurav Singh, Ashutosh Kumar, Devansh Maurya");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");

int init_module(void)
{
    printk(KERN_INFO "Hello world!\n");

    /*
     * A non 0 return means init_module failed; module can't be loaded.
     */
    return 0;
}

void cleanup_module(void)
{
    printk(KERN_INFO "Goodbye world!\n");
}
