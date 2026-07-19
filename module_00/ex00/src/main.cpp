/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:15:24 by daeunki2          #+#    #+#             */
/*   Updated: 2026/07/18 19:05:32 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"
#include "Color.hpp"

int main()
{
    Bank bank;

    std::cout << CYAN << "========== Encapsulation ==========" << RESET << std::endl;

    /*
        아래 코드는 컴파일이 되면 안 된다.

        Account a(1);
        a._value = 100;
        a.increase(100);
    */

    std::cout << GREEN << "Encapsulation test passed." << RESET << std::endl;


    std::cout << CYAN << "\n========== Create ==========" << RESET << std::endl;

    bank.createAccount(112233);
    bank.createAccount(256789);

    std::cout << bank << std::endl;


    std::cout << CYAN << "\n========== Deposit ==========" << RESET << std::endl;

    bank.deposit(112233, 1000);
    bank.deposit(256789, 500);

    std::cout << bank << std::endl;


    std::cout << CYAN << "\n========== Withdraw ==========" << RESET << std::endl;

    bank.withdraw(112233, 300);

    std::cout << bank << std::endl;


    std::cout << CYAN << "\n========== Loan ==========" << RESET << std::endl;

    bank.loanToAccount(256789, 50);

    std::cout << bank << std::endl;


    std::cout << CYAN << "\n========== Exception Tests ==========" << RESET << std::endl;

    try
    {
        bank.createAccount(1);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try
    {
        bank.deposit(999, 100);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try
    {
        bank.withdraw(1, 100000);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try
    {
        bank.deleteAccount(1);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try
    {
        bank.loanToAccount(2, 100000);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try
    {
        bank.deleteAccount(999);
    }
    catch (const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }


    std::cout << CYAN << "\n========== Delete ==========" << RESET << std::endl;

    bank.withdraw(256789, 525);
    bank.deleteAccount(256789);

    std::cout << bank << std::endl;


    std::cout << CYAN << "\n========== Final State ==========" << RESET << std::endl;

    std::cout << bank << std::endl;

    return 0;
}