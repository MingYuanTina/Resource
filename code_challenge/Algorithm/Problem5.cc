// May 29th, 2017
// -- basic I/O
// -- statically vs. dynamically store input into data structure
// -- end characters
// -- vector template
// Reference: 
// http://www.cplusplus.com/doc/tutorial/basic_io/

// Import libraries and files
#include <iostream>
#include "algorithm.h"
#include "selection.h"
#include "insertion.h"
#include "bubble.h"
#include "mergesorting.h"

// Namespace is a declarative region that provides a scope to identifiers
// std is C++ built-in namespace including all keywords for identifiers in built in libraries
using namespace std;

int main(){
	// Basic input and output
	// end == '\n' + std:flush
	// Reference: http://www.cplusplus.com/reference/ostream/ostream/flush/ 
	int total;
	string algo_selection;
	string algo_options[] = {"selection", "insertion"};

	// User Interface
	// Question 1: Size
	cout << "What is the size of your array: " << endl;
	cin >> total;
	int nums[total];
	// Question 2: Input
	cout << "Please insert element in your array: " << endl;
	for (int i = 0; i < total; i++){
		cin >> nums[i]; 
	}
	// Question 3: Input
	cout << "Please select algorithm you for sorting: " << endl;
	cin >> algo_selection;

	Algorithm *algo;
	if (algo_selection == "selection"){
		Selection selec_algo(nums, total);
		selec_algo.processAlgorithm();
		algo = &selec_algo;
	} else if (algo_selection == "insertion"){
		Insertion insert_algo(nums, total);
		insert_algo.processAlgorithm();
		algo = &insert_algo;
	} else if (algo_selection == "merge"){
		MergeSorting merge_algo(nums, total);
		merge_algo.processAlgorithm();
		algo = &merge_algo;
	} else if (algo_selection == "bubble"){
		Bubble bubble_algo(nums, total);
		bubble_algo.processAlgorithm();
		algo = &bubble_algo;
	} else {
		cerr << "Incorrect Input" << endl;
		return 0;
	}
	cout << algo->getName() << endl;
	cout << algo->getDescription() << endl;
	algo->printData();
	return 0;
}



