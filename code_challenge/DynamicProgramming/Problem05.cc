// Question
	// 198. House Robber
	// You are a professional robber planning to rob houses 
	// along a street. Each house has a certain amount of money stashed, 
	// the only constraint stopping you from robbing each of them is 
	// that adjacent houses have security system connected and it will 
	// automatically contact the police if two adjacent houses were broken into on the same night.
	// Given a list of non-negative integers representing the amount of money of each house, 
	// determine the maximum amount of money you can rob tonight without alerting the police.

// Test Cases	
	// A[1,1,1]	= 2
	// A[1,5,1] = 5
	// A[1,2,1,1] = 3
	// A[4,1,1,3] = 7

// Implementation
class Solution {
public:
    int rob(int num[], int n) {
    int even = 0, odd = 0;
    for (int i=0; i<n; i++){
        if (i%2 == 0) {
            even = max(even+num[i], odd);
        } else {
            odd = max(even, odd+num[i]);
        }
    }
    return max(even, odd);
		}
};