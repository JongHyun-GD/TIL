#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void )
{

}

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created\n";
}

Account::~Account( void )
{
	_totalAmount -= this->_amount;
	_nbAccounts--;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed\n";
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << "\n";
}



void	Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	_totalNbDeposits++;
	this->_amount += deposit;
	this->_nbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit
			  << ";deposit:" << deposit << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (this->_amount - withdrawal < 0) {
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << this->_amount
				  << ";withdrawal:refused\n";
		return false;
	}
	else {
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << this->_amount + withdrawal
				  << ";withdrawal:" << withdrawal
				  << ";amount:" << this->_amount
				  << ";nb_withdrawals:" << this->_nbWithdrawals
				  << "\n";
		return true;
	}

}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << "\n";
}

void	Account::_displayTimestamp( void )
{
	time_t curTime = time(NULL);
	struct tm *pLocal = localtime(&curTime);

	std::cout << std::setfill('0') << "[" << pLocal->tm_year + 1900
			  << std::setw(2) << pLocal->tm_mon
			  << std::setw(2) << pLocal->tm_mday << std::setw(0) << "_"
			  << std::setw(2) << pLocal->tm_hour
			  << std::setw(2) << pLocal->tm_min
			  << std::setw(2) << pLocal->tm_sec << std::setw(0) << "] ";
}
