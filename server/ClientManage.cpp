

#include "ClientManage.hpp"

void			ClientManage::ZeroBotList(void)
{
	FD_ZERO(&this->botlist);
	for (auto const& port : std::port_list)
		FD_SET(port, &(this->botlist));
}

