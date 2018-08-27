/* TestCard.cpp
 * test program for CreditCard class
 * Author: B. Kasper
 */

#include "CreditCard.h"				// provides CreditCard, cout, string
using namespace std;				// make std accessible

void testCard() {				// CreditCard test function
  // create 3 new cards
  CreditCard card1("5391 0375 9387 5309", "John Bowman", 2500);
  CreditCard card2("3485 0399 3395 1954", "Clark Kent", 3500);
  CreditCard card3("6011 4902 3294 2994", "Super Man", 5000);

  for (int j=1; j <= 16; j++) {			// make some charges
    card1.chargeIt(double(j));		// explicitly cast to double
    card2.chargeIt(2 * j);			// implicitly cast to double
    card3.chargeIt(double(3 * j));
  }

  cout << "Card payments:\n";
  // make payments on card1
  cout << card1;
  while (card1.getBalance() > 100.0) {
      card1.makePayment(100.0);
      cout << "Paid $100, New balance = " << card1.getBalance() << "\n";
    }
    cout << "\n";
  // make payments on card2
  cout << card2;
  while (card2.getBalance() > 100.0) {
      card2.makePayment(100.0);
      cout << "Paid $100, New balance = " << card2.getBalance() << "\n";
    }
    cout << "\n";
  // make payments on 3
  cout << card3;
  while (card3.getBalance() > 100.0) {
      card3.makePayment(100.0);
      cout << "Paid $100, New balance = " << card3.getBalance() << "\n";
    }
    cout << "\n";

  // storage for local variables (card1, card2, card3)
  // is automatically de-allocated when function returns
  }

int main() {					// main function
  testCard();
  return EXIT_SUCCESS;			// successful execution
}
