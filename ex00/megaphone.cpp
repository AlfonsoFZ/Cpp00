/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:26:34 by alfofern          #+#    #+#             */
/*   Updated: 2024/02/26 10:37:26 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(int ac, char *argv[])
{
	int i;
	int j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else 
	{
		for(i = 1; argv[i]; i++)
		{
			for(j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
		}
	}
	std::cout << std::endl;
	return (0);
}
