
#include "ClientManage.hpp"
#include "Net.hpp"

int		main(int argc, char **argv)
{
	Network		*server;

	if (argc != 2)
	{
		std::cout << "Usage : " << argv[0] << " [port number]" << std::endl;
		exit(1);
	}
	server = new Network(atoi(argv[1]));
	server->ZeroBotlist();

	server->CommandLoop();
	return (0);
}
