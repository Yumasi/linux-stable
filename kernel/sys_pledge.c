#include <linux/pledge.h>
#include <linux/slab.h>

int pledge_syscall(struct task_struct *task, int nr, uint64_t *tval)
{
	pr_info("(%s) Hooked syscall %lu\n", task->comm, nr);

	return 0;
}

int pledge(struct task_struct *task, const void *promises,
	   const void *exec_promises)
{
	if (!task->pledge_state) {
		task->pledge_state = kcalloc(1, sizeof(struct pledge_state),
					     GFP_KERNEL);
		if (!task->pledge_state)
			return ENOMEM;
	}

	task->pledge_state->state |= promises ? PLEDGED : 0;
	task->pledge_state->state |= exec_promises ? EXEC_PLEDGED : 0;

	pr_info("Hello, pledge!\n");

	return 0;
}
