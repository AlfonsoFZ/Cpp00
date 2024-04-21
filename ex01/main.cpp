/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:30:11 by alfofern          #+#    #+#             */
/*   Updated: 2024/02/26 10:56:55 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

/**
 * @brief launch the program and wait for the user to insert a command
 * 
 * An instance of the PhoneBook class is created and the user is asked to insert
 * a command that will be save in a string that we will compare with the options
 * to keep the program working we put all inside a infinte while loop.
 * we print an error message if the user insert a wrong command using the stc err
 *  "cerr".
 * removing the spaces after the input:
 * find_last_not_of() is used to find the last space or tab if it does not have
 * will return the value == to the sotre in this static constant std::string::npos 
 * So we use it to get a substring if they are diferent.
 * it is not requested but it is very common mistake to press the space bar wwhen 
 * a word is enteres so I have included for future references.
 * Spaces or/and tabs at the begining of the string are not removed in this code.
 * @return int 0 if success
 */
int main()
{
	if (DEBUG)
		std::cout << "DEBUG: main.cpp: main()" << std::endl;
	PhoneBook Book;;
	std::string cmnd;
	size_t lastpos;
	std::cout << std::endl;
	while(1)
	{
		std::cout<<  LIGHT_CYAN INS_CMND DEFAULT << std::endl << "\t";
		getline(std::cin, cmnd);
		lastpos = cmnd.find_last_not_of(" \t");
		if (std::string::npos != lastpos) {
			cmnd = cmnd.substr(0, lastpos + 1);
		}
		if(std::cin.eof())
		{
			std::cout << std::endl << LIGHT_RED << EOFINSERT << std::endl << DEFAULT;
			break;
		}
		if (!cmnd.compare("ADD"))
		{
			if (DEBUG)
				std::cout<< "ADD has been inserted"<<std::endl;
			std::cout << std::endl;
			Book.addContact();
			std::cout << std::endl;
		}
		else if (!cmnd.compare("SEARCH"))
		{
			if (DEBUG)
				std::cout<< "SEARCH has been inserted" << std::endl;
			std::cout << std::endl;
			Book.searchContact();
			std::cout << std::endl;
		}
		else if (!cmnd.compare("EXIT"))
		{
			std::cout << std::endl <<  LIGHT_CYAN EXITMSG DEFAULT << std::endl;
			std::cout << std::endl;
			break;
		}
		else
			std::cerr << LIGHT_RED BAD_CMND DEFAULT << std::endl;		
	}
	return (0);
}