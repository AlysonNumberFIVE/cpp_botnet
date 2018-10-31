


#ifndef COMMANDLIST_H
# define COMMANDLIST_H

#include <iostream>
#include <sys/sysctl.h>
#include <sys/types.h>


class CommandList {

	public:
		CommandList(void);
		~CommandList(void);
		void		GetSystemVersion(void);

};

#endif
