/* CreditCard.h
 * Authors: Goodrich, Tamassia and Mount (2011)
 * Description: from Code Fragments 1.2 and 1.3
 */

#ifndef CREDIT_CARD_H           // avoid repeated expansion
#define CREDIT_CARD_H

#include <string>				// provides string
#include <iostream>				// provides ostream
using namespace std;			// make std package accessible without std:: prefix

class CreditCard {
  public:
	// standard constructor
	CreditCard(string no, string nm, int lim, double bal=0);
	// accessors functions
	string   getNumber()    const   { return number; }
	string   getName()      const   { return name; }
	double   getBalance()   const   { return balance; }
	int      getLimit()     const   { return limit; }
	// update functions
	bool chargeIt(double price); 		// make a charge 
	void makePayment(double payment);	// make a payment

  private:              // private member data:
	string    number;		// credit card number
	string    name;			// card owner's name
	int       limit;		// credit limit
	double    balance;		// credit card balance
};

// standard constructor
CreditCard::CreditCard(string no, string nm, int lim, double bal) {
  number = no;
  name = nm;
  balance = bal;
  limit = lim;
}

// make a charge 
bool CreditCard::chargeIt(double price) {
  if (price + balance > double(limit)) 
      return false;				// over limit
  balance += price;
  return true;					// the charge goes through
}

void CreditCard::makePayment(double payment) { // make a payment
	balance -= payment;
}

// overload output operator to print CreditCard information
std::ostream& operator<<(std::ostream& out, const CreditCard& c) {
  out << "Number = "        << c.getNumber()      << "\n"
      << "Name = "          << c.getName()        << "\n"
      << "Balance = "       << c.getBalance()     << "\n"
      << "Limit = "         << c.getLimit()       << "\n";
  return out;
}

#endif