#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/*libraries*/
# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <limits>

/* colours */
# define DEFAULT	"\033[0m"
# define BOLD		"\033[1m"
# define RED		"\033[31;1m"
# define GREEN		"\033[32;1m"
# define BLACK		"\033[30;1m"
# define YELLOW		"\033[33;1m"
# define BLUE		"\033[34;1m"
# define MAGENTA	"\033[35;1m"
# define CYAN		"\033[36;1m"
# define WHITE		"\033[37;1m"
# define LIGHT_RED		"\033[91m"
# define LIGHT_GREEN	"\033[92m"
# define LIGHT_YELLOW	"\033[93m"
# define LIGHT_BLUE	"\033[94m"
# define LIGHT_MAGENTA	"\033[95m"
# define LIGHT_CYAN	"\033[96m"
# define LIGHT_WHITE	"\033[97m"
/* messages */
# define INS_CMND	" please insert: ADD, SEARCH or EXIT"
# define BAD_CMND	" wrong option: be careful with spaces and tabs"
# define EOFINSERT	"EOF has been inserted"
# define EXITMSG	" oh no! EXIT has been inserted so I'm done! \n\033[95m Bye bye!\033[0m"

class  PhoneBook
{

public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	searchContact();
	// void	display( void ) const;


private:
	Contact	_contacts[8];
	static void _printLeft(std::string s);
	int _printIndex();
	int _getIndex();

	// void printContact()

	// void	_removeFirst( void );
	// void	_printFormat( std::string s) const;
};

#endif