

#ifndef CLIENTMANAGE_HPP
# define CLIENTMANAGE_HPP

#include "Net.hpp"
#include <iostream>
#include <sys/select.h>
#include <vector>

class ClientManage {
	
	friend 					class Network;

	private:
		fd_set				botlist;
		std::vector<int>	port_list;

	public:
		ClientManage(void);
		~ClientManage(void);
		void		ZeroBotList(void);
};

#endif
