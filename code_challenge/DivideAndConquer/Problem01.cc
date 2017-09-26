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

// Implementation
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

int find_h_index(map<int, int> nums){
	// Recusive Step
	int low = 0; 
	int high = nums.size() - 1;  
  while(low <= high) {  
    int idx = (low+high)/2;  
    if(nums[idx] >= idx + 1) {  
      low = idx + 1;  
    } else {  
      high = idx - 1;  
    }  
  }  
  return low;
}

int main(){
	map<int, int>a;
	a[0] = 80;
	a[1] = 70;
	a[2] = 60;
	a[3] = 50;
	a[4] = 40;
	int h_index = find_h_index(a);
	cout << "result: " << h_index << endl;
	return h_index;
}