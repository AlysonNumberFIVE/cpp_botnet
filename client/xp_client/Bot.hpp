

#ifndef BOT_H
# define BOT_H

#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <vector>

class	DiagnosticBot {

	private:
		int							sockfd;
		struct sockaddr_in			address;
		fd_set						io_monitor;

	public:
		DiagnosticBot(int port, char *a);
		~DiagnosticBot(void);
		void	ErrorAndExit(std::string message);
		void	ZeroClientList(void);
		void	CommLoop(void);		
};

#endif

