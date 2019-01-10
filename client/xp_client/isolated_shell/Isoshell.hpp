






#ifndef _ISOSHELL_HPP
# define _ISOSHELL_HPP
# include <iostream>
# include <unistd.h>


class BuiltinCommands {

	pubilc:
		BuiltinComands( void );
		~BuiltinCommands( void );
		void 		Cd( std::string path );


};

#endif 
