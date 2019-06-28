#include <linux/pledge.h>

int pledge(struct task_struct *task, const void *promises,
	   const void *exec_promises)
{
	pr_info("Hello, pledge!\n");

	return 0;
}
