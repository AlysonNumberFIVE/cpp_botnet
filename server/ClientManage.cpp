

#include "ClientManage.hpp"

/*
** 	Sets up the socket list each loop as well as sets STDIN for listening
**  so user can write commands and dispatch them to clients.
*/

void			ClientManage::ZeroBotList(void)
{
	FD_ZERO(&this->botlist);
	for (auto const& port : std::port_list)
	{
		FD_SET(port, &(this->botlist));
		if (port > this->fd_max)
			this->fd_max = port;
	}
	FD_SET(0, &(this->botlist));
}

/*
** 	Main listening loop. Ports are monitored with SELECT for any incoming.
** 	connections from remote bots. 
*/

void			ClientManage::CommandLoop(void)
{
	int			r;

	for (;;)
	{
		r = select(this->fd_max + 1, &this->botlist, NULL, NULL, NULL);
		if (r)
		{

		}
	}
}

