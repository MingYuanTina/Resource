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

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());
        int low = 0; 
        int high = citations.size() - 1;  
          while(low <= high) {  
            int idx = (low+high)/2;  
            if(citations[idx] >= idx + 1) {  
              low = idx + 1;  
            } else {  
              high = idx - 1;  
            }  
          }  
          return low;
    }
};