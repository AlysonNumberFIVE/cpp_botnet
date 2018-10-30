











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
