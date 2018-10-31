



#include "CommandList.hpp"

CommandList::CommandList(void)
{
	return ;
}

CommandList::~CommandList(void)
{
	return ;
}

/*
** This will only work on MACOSX (and it's a very C function)
*/

void			CommandList::GetSystemVersion(void)
{
	char		buffer[128];
	size_t		size;

	size = 128;
	sysctlbyname("machdep.cpu.brand_string", &buffer, &size, NULL, 0);
	std::cout << buffer << std::endl;
}

