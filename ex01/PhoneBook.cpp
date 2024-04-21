/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:26:34 by alfofern          #+#    #+#             */
/*   Updated: 2024/02/26 11:20:25 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
	if (DEBUG)
		std::cout<< "Constructor has been called"<<std::endl;
}

PhoneBook::~PhoneBook()
{
	if (DEBUG)
		std::cout<< "Destructor has been called"<<std::endl;
}

void PhoneBook::addContact()
{
	if (DEBUG)
		std::cout<< "addContact has been called"<<std::endl;
	int pos;

	pos = Contact::getpos();
	_contacts[pos%8].add();

}

/**
 * @brief trunk and print the string to a maximum of 10 characters
 * 
 * @param str 
 * if str if larger than 10 characters, it will be truncated to 9 
 * characters and a dot will be added at the end, if not, it will be
 * right aligned to 10 characters, for that we can use 
 * 		// int spaces = 10 - str.length();
 *		// int leftPadding = spaces;
 *		// std::cout << std::setw(leftPadding) << "" << str;
 * or the code belw that set the width of the string to 10 and align it
 * to the right (left, right or internal)
 */
void PhoneBook::_printLeft(std::string str)
{

	int maxWidth = 10;
	
	std::cout << "|";
	if (int(str.length()) > maxWidth) {
		str = str.substr(0, maxWidth - 1) + ".";
		std::cout << std::setw(maxWidth) << str;
    }
	else
	{
		std::cout.width(maxWidth);
		std::cout << std::right << str;
	}
}

/**
 * @brief we use diferent colors to print the index and the contacts
 * even the message when the book is empty.
 * As no field can be empty, we can use the first name to check if the
 * contact is empty or not. and iterate the array of contacts to print
 * them only the fields already filled.
 * 
 * @return int 
 */
int PhoneBook::_printIndex()
{
	if (DEBUG)
		std::cout<< "printIndex has been called"<<std::endl;
	int i;
	std::cout << LIGHT_MAGENTA;
	std::cout << "┌-------------------------------------------┐" << std::endl;
	std::cout << "|     index|first Name| last Name|  nickname|" << std::endl;
	std::cout << "└-------------------------------------------┘" DEFAULT << std::endl;
	if (_contacts[0].FirstName == "")
	{
		std::cout << LIGHT_RED;
		std::cout << "┌-------------------------------------------┐" << std::endl;
		std::cout << "|      - No contacts to be displayed -      |" << std::endl;
		std::cout << "└-------------------------------------------┘" DEFAULT << std::endl;
		return (1);
	}
	std::cout << LIGHT_GREEN "┌-------------------------------------------┐" << std::endl;
	i = -1;
	while (++i < 8 && _contacts[i].FirstName != "")
	{
		std::cout << "|         " << i;
		_printLeft(_contacts[i].FirstName);
		_printLeft(_contacts[i].LastName);
		_printLeft(_contacts[i].NickName);
		std::cout << "|" << std::endl;
		if (i < 7 && _contacts[i + 1].FirstName != "")
			std::cout << "|-------------------------------------------|" << std::endl;
	}
	std::cout << "└-------------------------------------------┘" DEFAULT << std::endl;
	return (0);
}
cd 
/**
 * @brief request an input and validate it as the index to be displayed
 * as cin is used to store the value directly in the variable, we need to
 * clear the buffer and ignore the rest of the characters in the buffer.
 * if we don`t do it it will be used in the next cin call.
 * 
 * @return int 
 */
int PhoneBook::_getIndex()
{
	int index;
	
	index = -1;
	while (index < 0 || index > 7)
	{
		std::cout << LIGHT_YELLOW " please insert the index to display: " DEFAULT ;
		std::cin >> index;
		if (std::cin.eof())
		{
			std::cout << std::endl << LIGHT_RED << EOFINSERT << std::endl << DEFAULT;
			exit(0);
		}
		else if (std::cin.fail())
		{
			std::cout << LIGHT_RED " -- wrong index -- " DEFAULT << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			index = -1;
		}
		else if (_contacts[index].FirstName == "" || index < 0 || index > 7)
		{	
			std::cout << LIGHT_RED " -- Empty contact or index out of range -- " DEFAULT << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return (-1);
		}	
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (index);
}

/**
 * @brief launch the Search funtion that will print the index, request it and
 * if a valid index is inserted, it will print the contact information
 * 
 */
void PhoneBook::searchContact()
{
	int index;
	if (DEBUG)
		std::cout<< "searchContact has been called"<<std::endl;
	if (this->_printIndex())
		return;
	index = _getIndex();
	if (index != -1)
	{	std::cout << LIGHT_GREEN "---------------------------------------------" << std::endl;
		std::cout << std::endl;
		_contacts[index].printContact();
		std::cout << std::endl;
		std::cout << LIGHT_GREEN "---------------------------------------------" DEFAULT << std::endl;
	}
}
