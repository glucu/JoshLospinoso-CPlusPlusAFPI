
/*  You didn’t implement an accounting system in your Bank. 
 *  Design an interface called AccountDatabase that can retrieve and set amounts in bank accounts
 *  (identified by a long id).
 */

class AccountDatabase {
public:
    virtual ~AccountDatabase() = default;
    virtual void retrieve_and_set(long from, long to, double amount) = 0;
};