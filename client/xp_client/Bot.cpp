
#include "Bot.hpp"

DiagnosticBot::DiagnosticBot(int port, char *a)
{
	this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&this->address, 0, sizeof(struct sockaddr_in));
	this->address.sin_family = AF_INET;
	this->address.sin_addr.s_addr = inet_addr(a);
	this->address.sin_port = htons(port);
	if (connect(this->sockfd, (struct sockaddr *)&this->address, 
				sizeof(this->address)) < 0)
		ErrorAndExit("Error : connect");
	return ;
}

DiagnosticBot::~DiagnosticBot(void)
{
	close(this->sockfd);
}

void		DiagnosticBot::ErrorAndExit(std::string msg)
{
	std::cout << msg << std::endl;
	exit(1);
}

void		DiagnosticBot::ZeroClientList(void)
{
	FD_ZERO(&this->io_monitor);
	FD_SET(this->sockfd, &this->io_monitor);
}


std::string		DiagnosticBot::ReceiveCommand(void)
{
	ssize_t			bytesize;
	char			buffer[513];

	bytesize = recv(this->sockfd, buffer, 512, 0);
	buffer[bytesize] = '\0';
	std::string		command(buffer);
	return (command);	
}

void		DiagnosticBot::CommLoop(void)
{
	CommandList			commandlist;
	std::string			command;

	for ( ;; ) 
	{
		select(this->sockfd, &this->io_monitor, NULL, NULL, NULL);
		if (FD_ISSET(this->sockfd, &this->io_monitor))
		{
			command = ReceiveCommand();
		}
	}
}


