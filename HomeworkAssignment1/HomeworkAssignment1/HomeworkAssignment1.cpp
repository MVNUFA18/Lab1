/* HomeworkAssignment1.cpp
 * Dante Cherubini
 * August 31, 2018
*/

#include "pch.h"
#include "CreditCard.h"
#include <iostream>
using namespace std;


int main()
{
	double charge;
	double payment = 100.0;

	CreditCard NewCard("45", "Dante", 700, 0.0);

	for (int i = 0; i < 4; i++) {
		cout << "Enter an amount to charge: ";
		cin >> charge;
		while (!NewCard.chargeIt(charge)) {
			cout << "This would exceed the limit! Enter a new amount to charge: ";
			cin >> charge;
		}
		cout << "New Balance: " << NewCard.getBalance() << endl;
	}
	NewCard.makePayment(payment);
	cout << "$" << payment << " was paid! The new balance is: " << NewCard.getBalance();
}
