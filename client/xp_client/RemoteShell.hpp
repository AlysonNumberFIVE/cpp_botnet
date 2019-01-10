


#ifndef REMOTESHELL_HPP
# define REMOTESHELL_HPP

#include <unistd.h>
#include <vector>
#include <iostream>

#ifndef __APPLE__		// <filesystem> doesn't seem to exist on Apple systems.
#include <filesystem>
#endif

class RemoteShell {

	private:
		std::string		TravereDir(std::string dir, std::string comm);

	public:
		RemoteShell(void);
		~RemoteShell(void);
		std::vector<std::string> stringsplit(std::string str, std::string c);
		void					RemoteDir(std::string command);
		void					ChangeDir(std::string command);
		void					ExecveShell(std::string command);
};

#endif 
