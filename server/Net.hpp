

#ifndef NETWORK_HPP
# define NETWORK_HPP

#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/*
**	Server class
*/

class Network {

	private:
		int					sockfd;
		struct sockaddr_in	sockaddr;
	public:
		Network(int port_number);			// initalize botnet.
		~Network(void);						// close main socket.
		void error_and_exit(std::string);	// print error message and exit
};






#endif
