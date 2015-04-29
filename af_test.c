#include <linux/module.h>
#include "af_test.h"


MODULE_DESCRIPTION("My new network protocol - AF_TEST");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Venkatesh Parthasarathy");

static __init int af_test_init(void) {
	printk("TODO init...\n");
	return 0;
}

static __exit int af_test_exit(void) {
	printk("TODO exit...\n");
}

module_init(af_test_init);
module_exit(af_test_exit);
