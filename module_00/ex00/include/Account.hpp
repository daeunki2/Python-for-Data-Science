/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:15:08 by daeunki2          #+#    #+#             */
/*   Updated: 2026/07/18 18:16:47 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>

class Account
{
private:
    int _id;
    size_t _value;

    Account(int id);

public:
    int get_Id() const;
    int get_Value() const;
	void increase(size_t amount);
    void decrease(size_t amount);

    friend std::ostream& operator<<(std::ostream& os,const Account& account);

    friend class Bank;
};

#endif