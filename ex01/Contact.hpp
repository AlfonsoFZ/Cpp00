#ifndef CONTACT_HPP
# define CONTACT_HPP
 #include <iostream>
 #include <string>

class Contact {
  	public:
		Contact( void );
		~Contact( void );
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string	PhoneNumber;
		std::string DarkestSecret;
		void add( void );
		static int getpos( void );
		void printContact( void );

	private:
		std::string get_info(std::string, std::string);
 		static int	_pos;
};
#endif

