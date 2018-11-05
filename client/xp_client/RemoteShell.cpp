
#include "RemoteShell.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

RemoteShell::RemoteShell(void)
{
	return ;
}

RemoteShell::~RemoteShell(void)
{
	return ;
}

std::vector<std::string>		RemoteShell::stringsplit(std::string s, std::string c)
{
	std::vector<std::string> list;
    size_t pos = 0;
	std::string token;
  
	s = s + c;
	while ((pos = s.find(c)) != std::string::npos) 
	{
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + c.length());
    }
    return list;
}

void		RemoteShell::ChangeDir(std::string command)
{
	std::vector<std::string> 		list;
	std::string						args;
	const char						*strt;

	list = stringsplit(command, " ");
	if (list.size() == 1)
		chdir("/");
	else if (list.size() == 2)
	{
		strt = strchr(command.c_str(), ' ');
		++strt;
		chdir(strt);
	}
}

std::string TraverseDir(std::string dir, std::string comm)
{
#ifndef __APPLE__
	for (auto const &name : dir)
		for (auto const &file : directory_iterator(name))
		{
			std::vector<std::string> filename = stringsplit(file, "/");
			if (filename == comm)
				return (file);
		}
#endif
	return ("");
}

void		RemoteShell::ExecveShell(std::command)
{
	std::vector<std::string> 		list;
	std::string						args;
	int								i;
	std::string						pathway;
	std::vector<std::string>		path;

	extern char						**environ;

	list = stringsplit(command, " ");
	i = -1;
	while (environ[++i])
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			pathway(environ[i]);
			break ;
		}
	path = split(pathway, "=");
	std::string directories = path.at(1);
	std::vector<std::string> list = stringsplit(directories, ":");
	for (auto const &list : plc)
		std::exec_string = TraverseDir(plc, list.at(0));

}

int	 main(void)
{
	return (0);
}

