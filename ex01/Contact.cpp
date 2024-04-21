/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:26:34 by alfofern          #+#    #+#             */
/*   Updated: 2024/02/26 10:55:54 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief Construct a new Contact:: Contact object
 * in this case it is really not needed as it is the default constructor, but 
 * sometimes you need to define a constructor to initialize the object's state
 */
Contact::Contact(void)
{
	if (DEBUG)
		std::cout << "Contact's constructor called" << std::endl;
}

/**
 * @brief Destroy the Contact:: Contact object	
 *  it will calles once the function that contains the object is finished
 */
Contact::~Contact()
{
	if (DEBUG)
		std::cout << "Contact's destructor called" << std::endl;
}

/**
 * @brief request the user to insert the info for the contact
 * "info" string is declared to save the input from the user.
 * first af all it clears the input buffer, 
 * then print the prompt1 and prompt2 indicating which field is requested
 * then it gets the input from the user and save it in the "info" string
 * if the user insert EOF (ctrl + d), the program will print a message and exit
 * if the string is empty, the program will print a message and request
 * the user to insert a valid input.
 * @param prompt1 
 * @param prompt2 
 * @return std::string 
 */
std::string Contact::get_info(std::string prompt1, std::string prompt2)
{
	std::string info;

	std::cin.clear();
	std::cout<< LIGHT_GREEN << prompt1 << prompt2 << "  " << DEFAULT;
	std::getline(std::cin, info); 
	if(std::cin.eof())
	{
		std::cout << std::endl << LIGHT_RED << EOFINSERT << std::endl << DEFAULT;
		exit (1);
	}
	while (info.empty())
	{
		std::cout << LIGHT_RED " please enter a valid input for " << prompt2 << DEFAULT << "  ";
		std::getline(std::cin, info);
		if(std::cin.eof())
		{
			std::cout << std::endl << LIGHT_RED << EOFINSERT << std::endl << DEFAULT;
			exit (1);
		}
	}
	return (info);
}

 /**
  * @brief this function will add a contact to the phonebook by launching
  * the get_ingo funtion that will request the user to insert the info
  * and will increment the pos static variable.
  * "prompt1" and "prompt2" are the arguments for the get_info function
  * and have been splitted just to show only the last part of the prompt 
  * if a field info is not fulfilled properly
*/
void Contact::add( void )
{
	if (DEBUG)
		std::cout << "Contact add has been called" << std::endl;
	FirstName = get_info(" please enter the ","first name:");
	LastName = get_info(" please enter the ", "last name:"); 
	NickName = get_info(" please enter the ", "nickname:");
	PhoneNumber = get_info(" please enter the ", "phone number:");
	DarkestSecret = get_info(" and please enter the ", "darkest secret:");
	_pos++;
}

/**
 * @brief this function will swhow the contact information
 * 
 */
void Contact::printContact( void )
{	std::cout<< LIGHT_GREEN;
	std::cout<< " First Name: \t " << this->FirstName << std::endl;
	std::cout<< " Last Name: \t " << this->LastName << std::endl;
	std::cout<< " Nick Name: \t " << this->NickName << std::endl;
	std::cout<< " Phone Number: \t " << this->PhoneNumber << std::endl;
	std::cout<< " Darkest Secret: " << this->DarkestSecret << std::endl;
	std::cout<< DEFAULT;
}

/**
 * @brief get the value of the private static variable _pos
 *	we need a getter to access the value of the private static variable _pos
 * as it cannot be accessed from outside the class
 * @return int the value of _pos
 */
int Contact::getpos( void )
{
	return Contact::_pos;
}

/**
 * @brief her we iniciate the static variable _pos that is a non-member
 * variable and can be used with no instances of the class
 * it is dcelaed in the Contact.hpp file as:
 * 	static int	_pos; 
 */
int	Contact::_pos = 0;
