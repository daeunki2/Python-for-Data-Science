/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:15:15 by daeunki2          #+#    #+#             */
/*   Updated: 2026/07/18 18:56:08 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BANK_HPP
#define BANK_HPP

#include <vector>
#include "Account.hpp"

/*
- 은행은 고객 계좌로 들어오는 각 입금액의 5%를 받아야 합니다.
- 두 계좌가 동일한 ID를 가져서는 안 됩니다.
- 구조체의 속성은 외부에서 수정할 수 없어야 합니다.
- 은행은 고객 계좌를 생성하고, 삭제하고, 수정할 수 있어야 합니다.
- 은행은 보유 자금의 범위 안에서 고객에게 대출할 수 있어야 합니다.
- 은행을 통하지 않고 고객 계좌에 돈을 추가하는 것은 불가능해야 합니다.
- 타당한 경우 Getter와 Setter를 반드시 만들어야 합니다.  
  복사본을 반환하는 Getter는 허용되지 않습니다.
- 타당한 경우 `const` Getter를 반드시 만들어야 합니다.  
  복사본을 반환하는 `const` Getter는 허용되지 않습니다.
*/

class Bank
{
private:
    size_t _liquidity;
    std::vector<Account*> _accounts;

    Account* findAccount(int id); // 수정
    const Account* findAccount(int id) const; // 조회

    Bank(const Bank& other); // 복사 금지를 위해 선언만 해둔다.
    Bank& operator=(const Bank& other); // 복사 금지를 위해 선언만 해둔다.
	

public:
    Bank();
    ~Bank();

    Account& createAccount(int id);
    void deleteAccount(int id);

    void deposit(int id, size_t amount);
    void withdraw(int id, size_t amount);
    void loanToAccount(int id, size_t amount);

    size_t getLiquidity() const;

	friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);
};

#endif