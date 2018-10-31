
#include "Net.hpp"

/*
** 	Createse command server and prepares it for listening in for
**	remote bot connection.
*/

Network::Network(int port_number)
{
	if ((Network::sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		ErrorAndExit("Error : socket");
	memset(&this->sockaddr, 0, sizeof(struct sockaddr_in));
	this->sockaddr.sin_family = AF_INET;
	this->sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	this->sockaddr.sin_port = htons(port_number);
	std::cout << "Binding to port " << port_number << std::endl;
	if (bind(this->sockfd, (struct sockaddr *)&this->sockaddr,
		sizeof(this->sockaddr)) < 0)
		ErrorAndExit("Error : bind");
	std::cout << "Socket ready to accept incoming connections " << std::endl;
	std::cout << "Listening... " << std::endl;
	if (listen(this->sockfd, 5) < 0)
		ErrorAndExit("Error : listen");
}

/*
**	Close open socket connection.
*/

Network::~Network(void)
{
	close(this->sockfd);
}

/*
** prints error message and leaves
*/

void		Network::ErrorAndExit(std::string message)
{
	std::cout << message << std::endl;
	exit(1);
}

/*
** 	Sets up the socket list each loop as well as sets STDIN for listening
**  so user can write commands and dispatch them to clients.
*/

void			Network::ZeroBotlist(void)
{
	this->fd_max = this->sockfd;

	FD_ZERO(&this->botlist);
	for (int const& port : this->port_list)
	{
		FD_SET(port, &(this->botlist));
		if (port > this->fd_max)
			this->fd_max = port;
	}
	FD_SET(this->sockfd, &(this->botlist));
	FD_SET(0, &(this->botlist));
}

/*
** Accept user 
*/

void		Network::NewConnection(void)
{
	socklen_t	value;
	int			newUser;

	value = sizeof(this->sockaddr);
	newUser = accept(this->sockfd, (struct sockaddr *)&this->sockaddr,
		(socklen_t *)&value);
	this->address_port[inet_ntoa(this->sockaddr.sin_addr)] = newUser;

	/**** Printing out connection info ****/
	std::cout << "Connection from " << inet_ntoa(this->sockaddr.sin_addr) <<
	" Port : " << this->address_port[inet_ntoa(this->sockaddr.sin_addr)] <<
	std::endl;
	/*************************************/
}

/*
** Main server loop: monitors STDIN and botlist.
** responds to bots joining or input from user
*/

void		Network::CommandLoop(void)
{
	int			r;

	for (;;)
	{
		r = select(this->fd_max + 1, &this->botlist, NULL, NULL, NULL);
		if (r)
		{
			if (FD_ISSET(this->sockfd, &this->botlist))
				NewConnection();
			return ;
		}
	}
}


