


#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int	main(void)
{
	printf("address : %s \n", inet_ntoa("216.58.223.74"));
	return (0);
}
