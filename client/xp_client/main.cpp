


#include "Bot.hpp"

int			main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage : " << argv[0] << " [server] [port] " << std::endl;
		exit(1);
	}
	DiagnosticBot			*bot;

	bot = 	new DiagnosticBot(atoi(argv[2]), argv[1]);	
	bot->ZeroClientList();
	bot->CommLoop();

	return (0);
}
