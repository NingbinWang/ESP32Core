#ifndef _ACCOUNT_BROKER_H_
#define _ACCOUNT_BROKER_H_

#include "Account.h"

class AccountBroker
{
public:
    /* The name of the data center will be used as the ID of the main account */
    const char* Name;

    /* Main account, will automatically follow all accounts */
    Account AccountMaster;

public:
    AccountBroker(const char* name);
    ~AccountBroker();
    bool AddAccount(Account* account);
    bool RemoveAccount(Account* account);
    bool Remove(std::vector<Account*>* vec, Account* account);
    Account* SearchAccount(const char* id);
    Account* Find(std::vector<Account*>* vec, const char* id);
    uint32_t GetAccountLen();

private:

    /* Account pool */
    std::vector<Account*> AccountPool;
};


#endif // !_ACCOUNT_BROKER_H_
