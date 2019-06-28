#ifndef PLEDGE_H
#define PLEDGE_H

#include <linux/sched.h>

int pledge(struct task_struct *task, const void *promises,
	   const void *exec_promises);

#endif /* !PLEDGE_H */
