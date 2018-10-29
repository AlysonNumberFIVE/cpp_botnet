

#ifndef NETWORK_HPP
# define NETWORK_HPP

#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <sys/select.h>

/*
**	Server class
*/

class Network {

	private:
		int						sockfd;
		int						fd_max;
		struct sockaddr_in		sockaddr;
		std::vector<int>		port_list;
		fd_set					botlist;
		

	public:
		Network(int port_number);			// initalize botnet.
		~Network(void);						// close main socket.
		void ErrorAndExit(std::string);	// print error message and exit
		void ZeroBotlist(void);
		void CommandLoop(void);

};






#endif
