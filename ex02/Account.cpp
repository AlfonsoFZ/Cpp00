/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:26:34 by alfofern          #+#    #+#             */
/*   Updated: 2024/02/25 14:10:24 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Account.hpp"
#include <iostream>
#include <ctime>

int	Account::getNbAccounts( void ){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (Account::_totalNbDeposits);	
}
int	Account::getNbWithdrawals( void ){
	return (Account::_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void ){
	
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( void ){
	std::cout << "Account Constructor called" << std::endl;
}
Account::Account( int initial_deposit ){

	_accountIndex = _nbAccounts;
	_amount = initial_deposit;	
	_nbDeposits = _totalNbDeposits;
	_nbWithdrawals = _totalNbWithdrawals;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
	_totalAmount+=initial_deposit;
}
Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
	std::cout << ";deposit:" << deposit << ";amount:" << _amount;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;

}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
		std::cout << ";withdrawal:refused" << std::endl;
	}
	else
	{
		_nbWithdrawals++;
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
		_amount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	return (true);
}
int		Account::checkAmount( void ) const
{
	return (_amount);
}
void	Account::displayStatus( void ) const
{
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount \
	<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals	<< std::endl;

	
}

void	Account::_displayTimestamp( void )
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer,80, "[%G%m%d_%I%M%S]",timeinfo);
	std::cout << buffer << " ";
}
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
