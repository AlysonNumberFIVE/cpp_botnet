
#ifndef BOT_H
# define BOT_H


class Bot {

	private:
		int					sockfd;
		struct sockaddr_in	address;
	
	public:
		Bot(int port);
		~Bot(void);

};


#endif
