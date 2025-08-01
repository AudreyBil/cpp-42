/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:42:08 by abillote          #+#    #+#             */
/*   Updated: 2025/07/16 11:16:58 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account()
{

};

Account::Account( int initial_deposit )
: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount << ";created" << std::endl;
};

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount << ";closed" << std::endl;
};

void	Account::makeDeposit( int deposit )
{
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";p_amount:" << p_amount << ";deposit:" << deposit
			  << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = _amount;
	if (_amount - withdrawal < 0)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex
				  << ";p_amount:" << p_amount << ";withdrawal:refused" << std::endl;
		return 0;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals
			  << std::endl;
	return 1;
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:"
			  << _amount << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t rawTimestamp;
	struct tm *timeinfo;
	time(&rawTimestamp);
	timeinfo = localtime(&rawTimestamp);

	std::cout << "["
			  << (timeinfo->tm_year + 1900)
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_mon + 1
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_mday
			  << "_"
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_hour
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_mday
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_sec
			  << "]";
}
