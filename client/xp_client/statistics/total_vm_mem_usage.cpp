





#include <iostream>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/mount.h>


#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdio.h>

#define BUFFERLEN 128

int main(){
    char buffer[BUFFERLEN];
    size_t bufferlen = BUFFERLEN;
   int i =  sysctlbyname("machdep.cpu.brand_string",&buffer,&bufferlen,NULL,0);
 	printf("%d\n", i);
  	printf("%s\n", buffer);
}
/*
int		main(void)
{
	xsw_usage		vmusage = {0};
	size_t size		= sizeof(vmusage);
	if (sysctlbyname("vm.swapusage", &vmusage, &size, NULL, 0) != 0)
	{
		std::cout << "Unable to get swap usage " << std::endl;
	}
	return (0);
} */
