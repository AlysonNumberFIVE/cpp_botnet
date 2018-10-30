



#include "Bot.hpp"

Bot::Bot(int port)
{
	this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&this->address, 0, sizeof(struct sockaddr_in));
	this->address.sin_family = AF_INET;
	this->address.sin_addr.s_addr = htons(INADDR_ANY);
	this->address.sin_port = htonl(port);
}
