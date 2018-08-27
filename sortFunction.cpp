/* sortFunction.cpp
 * Author: Bob Kasper
 * Demonstrate a main function calling a function to sort an array in C++.
 */

#include <iostream>			// library defines cout and cin streams
#include <cstdlib>		 	// library defines rand() and srand()
#include <ctime>			// library defines time(), used to seed srand()
using namespace std;

#define SIZE 10				// constant definition using a macro

/* Sort the array a[] in ascending order using insertion sort algorithm.
 */
void sort(int a[], int size) {
	for (int i = 1; i < size; i++) {
		// a[0..i-1] is sorted
		// insert a[i] in the proper place
		int x = a[i];
		int j;
		for (j = i - 1; j >= 0; --j) {
			if (a[j] <= x)
				break;
			a[j + 1] = a[j];
		}
		// now a[0..j] are all <= x and a[j+2..i] are > x
		a[j + 1] = x;
	}
}

int main() {
	int score[SIZE];		// declare array to be sorted

	cout << "Sorting Demo" << endl;
	//seed the random number generator (Only needs to be done once!)
	srand((unsigned int) time(0));

	// read the first number into the score array
	cout << "Enter the first score (integer): " << flush;
	cin >> score[0];

	// set the remaining array elments with random values
	for (int i = 1; i < SIZE; i++)
        score[i] = rand()%100;
    cout << "Array before sorting:";
    for (int i = 0; i < SIZE; i++)
        cout << " " << score[i];
    cout << endl;

    sort(score, SIZE);		// call the sort function

    cout << "Array after sorting: ";
    for (int i = 0; i < SIZE; i++)
        cout << " " << score[i];
    cout << endl;
	return 0;
}