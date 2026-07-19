/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:15:04 by daeunki2          #+#    #+#             */
/*   Updated: 2026/07/18 18:15:53 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int id)
    : _id(id), _value(0)
{
	
}

int Account::get_Id() const
{
	return _id;
}

int Account::get_Value() const
{
	return _value;
}

void Account::increase(size_t amount)
{
    if (amount > std::numeric_limits<size_t>::max() - _value)
        throw std::runtime_error("Amount is too large");

    _value += amount;
}

void Account::decrease(size_t amount)
{
    if (amount > _value)
        throw std::runtime_error("Insufficient balance");

    _value -= amount;
}

std::ostream& operator<<(std::ostream& os, const Account& account)
{
    os << "[" << account._id << "] : " << account._value;
    return os;
}
