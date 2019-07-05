#ifndef PLEDGE_H
#define PLEDGE_H

#include <linux/sched.h>

/*
 * Task pledge(2) state
 */
#define PLEDGED 1
#define EXEC_PLEDGED 2

struct pledge_state {
	char state;
	uint64_t promises;
	uint64_t exec_promises;
};

int pledge(struct task_struct *task, const void *promises,
	   const void *exec_promises);

#endif /* !PLEDGE_H */
