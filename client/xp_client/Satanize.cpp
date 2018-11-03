

#include "Bot.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

void			Satanize(DiagnosticBot *bot) 
{
	pid_t	pid; 
	pid_t	sid;

	pid = fork();
	if (pid < 0) 
		exit(EXIT_FAILURE);
	if (pid > 0)
		exit(EXIT_SUCCESS);
	umask(0);
	sid = setsid();
	if (sid < 0)
		exit(EXIT_FAILURE);
//	if ((chdir("/")) < 0)
//		exit(EXIT_FAILURE);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	for ( ;; ) 
	{
		bot->ZeroClientList();
		bot->CommLoop();
	}
	exit(EXIT_SUCCESS);
}
