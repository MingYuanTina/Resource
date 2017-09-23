// This is assignment first question for CS 341
	// Divide-and-conquer. 
	// One popular way to rank researchers is by their “h- index”. 
	// A researcher’s h-index is the maximum integer k such that the researcher 
	// has at least k papers that have been cited at least k times each. 
	// Suppose Professor X has written n papers and paper i has been cited ci times. 
	// Suppose you have these sorted in an array C with c1 > c2 > . . . > cn. 
	// Give a divide-and-conquer algorithm to find Professor X’s h-index

// Runtime Constraint: O(logn)
// Space Constraint: Non-specified

// Test Cases
	// [] -> 0
	// [1] -> 1
	// [0, 1] -> [1]
	// [3,2,1] -> [2]
	// [5,4,3,2,1] -> [3]
	// [4,3,2,1,0] -> [2]

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int find_h_index(vector<int> & nums){
	// Base Case
	if (nums.size() == 0)
		return 0;
	if (nums.size() == 1)
		return nums[0];
	// Recursive Case (Divide and Conquer Algorithm)
	// Divide
	int half = nums.size() / 2; 
	vector<int> first_half;
	for (int i = 0; i < half; i++){
		first_half.push_back(nums[i]);
	}
	vector<int> second_half;
	for (int i = half; i < nums.size(); i++){
		second_half.push_back(nums[i]);
	}
	int l1 = find_h_index(first_half);
	int l2 = find_h_index(second_half);
	// Conquer
	if (l1 < second_half[0])
		return l1 + l2;
	else 
		return l1;
}

int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(0);
	int h_index = find_h_index(a);
	cout << "result: " << h_index << endl;
	return h_index;
}