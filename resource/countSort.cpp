#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	int total, max, min;
	cin >> total;					// Read first element as total
	int A[total], B[total];	

	// Read Input from each line
	// Run time: O(n)
	for (int i = 0; i < total; i++){
		cin >> A[i];				// Read in each number
		B[i] = A[i];				// Make copy of A to B
		if (A[i] > max || i == 0)	// Update max
			max = A[i];
		if (A[i] < min || i == 0)	// Update min
			min = A[i];
	}

	// Count how many of each kind there are
	// Run time: O(k)
	int C[max - min + 1];
	for (int i = 0; i < max - min + 1; i++){
		C[i] = 0;
	}

	// Increment C[b] where b is A[i] shift min down
	// Run time: O(n)
	for (int i = 0; i < total; i++){
		C[A[i] - min] += 1;
	}

	// Find left boundary for each kind
	// Run time: O(k)
	int I[max - min + 1];
	I[0] = 0;
	for (int i = 1; i < max - min + 1; i++){
		I[i] = I[i-1] + C[i-1];
	}

	// Move back in sorted order
	// Run time: O(n)
	for (int i = 0; i < total; i++){
		A[I[B[i] - min]] = B[i];
		I[B[i] - min] += 1;
	}

	// Print out sorted array 
	// Run time: O(n)
	for (int i = 0; i < total; i++){
		cout << A[i] << endl;
	}

	return 0;

}