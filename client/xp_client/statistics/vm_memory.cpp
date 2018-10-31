







#include <iostream>
#include <sys/param.h>
#include <sys/mount.h>

uint64_t	total_vm_memory(void)
{
	uint64_t		freeSwap;
	struct statfs	stats;

	if (0 == statfs("/", &stats))
	{
		freeSwap = (uint64_t)stats.f_bsize * stats.f_bfree;
	}
	return (freeSwap);
}

int		main(void)
{
	total_vm_memory();
	return (0);
}
