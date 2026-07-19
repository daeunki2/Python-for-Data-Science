/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:15:11 by daeunki2          #+#    #+#             */
/*   Updated: 2026/07/18 18:56:21 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"

Bank::Bank()
	: _liquidity(0)
{

}

Bank::~Bank()
{
    for (std::size_t i = 0; i < _accounts.size(); ++i)
        delete _accounts[i];
}

Account* Bank::findAccount(int id)
{
    for (std::size_t i = 0; i < _accounts.size(); ++i)
    {
        if (_accounts[i]->get_Id() == id)
            return _accounts[i];
    }
    return NULL;
}

const Account* Bank::findAccount(int id) const
{
	for (std::size_t i = 0; i < _accounts.size(); ++i)
    {
        if (_accounts[i]->get_Id() == id)
            return _accounts[i];
    }
    return NULL;
}


Account& Bank::createAccount(int id)
{
    if (findAccount(id) != NULL)
        throw std::runtime_error("Account ID already exists");

	Account* account = new Account(id);

	try
	{
		_accounts.push_back(account);
	}
	catch (...)
	{
		delete account;
		throw;
	}
	return *account;
}

void Bank::deleteAccount(int id)
{
    for (std::vector<Account*>::iterator it = _accounts.begin(); it != _accounts.end(); ++it)
    {
        if ((*it)->get_Id() == id)
        {
            if ((*it)->get_Value() != 0)
                throw std::runtime_error("Account is not empty");

            Account* account = *it;
            _accounts.erase(it);
            delete account;
            return;
        }
    }

    throw std::runtime_error("Account ID does not exist");
}

void Bank::deposit(int id, size_t amount)
{
    Account* account = findAccount(id);

    if (account == NULL)
        throw std::runtime_error("Account ID does not exist");

    size_t fee = amount * 5 / 100;

    if (fee > std::numeric_limits<size_t>::max() - _liquidity)
        throw std::runtime_error("Liquidity overflow");

    account->increase(amount - fee);
    _liquidity += fee;

    std::cout << fee << " is taken as a fee" << std::endl;
}

void Bank::withdraw(int id, size_t amount)
{
    Account* account = findAccount(id);

    if (account == NULL)
        throw std::runtime_error("Account ID does not exist");

    account->decrease(amount);
}

void Bank::loanToAccount(int id, size_t amount)
{
    Account* account = findAccount(id);

    if (account == NULL)
        throw std::runtime_error("Account ID does not exist");

    if (_liquidity < amount)
        throw std::runtime_error("Bank has insufficient liquidity");

    account->increase(amount);
    _liquidity -= amount;
}

size_t Bank::getLiquidity() const
{
    return _liquidity;
}

std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank)
{
    p_os << "Bank informations:" << std::endl;
    p_os << "Liquidity: " << p_bank._liquidity << std::endl;

    for (std::size_t i = 0; i < p_bank._accounts.size(); ++i)
        p_os << *(p_bank._accounts[i]) << std::endl;

    return p_os;
}