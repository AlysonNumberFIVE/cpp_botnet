
#include "Net.hpp"

/*
** 	Createse command server and prepares it for listening in for
**	remote bot connection.
*/

Network::Network(int port_number)
{
	this->sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	memset(&this->sockaddr, 0, sizeof(struct sockaddr_in));
	this->sockaddr.sin_family = AF_INET;
	this->sockaddr.sin_addr.s_addr = INADDR_ANY;
	this->sockaddr.sin_port = port_number;
	std::cout << "Binding to port " << port_number << std::endl;
	if (bind(this->sockfd, (struct sockaddr *)&this->sockaddr,
		sizeof(struct sockaddr)) < 0)
		error_and_exit("Error : bind");
	std::cout << "Socket ready to accept incoming connections " << std::endl;
	std::cout << "Listening... " << std::endl;
}

/*
**	Close open socket connection.
*/

Network::~Network(void)
{
	close(this->sockfd);
}

void		Network::error_and_exit(std::string message)
{
	std::cout << message << std::endl;
	exit(1);
}

