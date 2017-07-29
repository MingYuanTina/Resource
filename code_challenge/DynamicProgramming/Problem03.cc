// Question
	// 70. Climbing Stairs
	// You are climbing a stair case. 
	// It takes n steps to reach to the top.
	// Each time you can either climb 1 or 2 steps. 
	// In how many distinct ways can you climb to the top?
	// Note: Given n will be a positive integer.

// Test Cases	
	// 1 -> 1
	// 2 -> 2
	// 3 -> 3
	// 4 -> 5

// Runtime
	// Time Complexity:  O(n)
	// Space Complexity: O(n)

// General Strategy
	// step[n] = step[n-1] + step[n-2]

// Solution
class Solution {
public:
    int climbStairs(int n) {
        vector<int>l(n, 0);
        l[0] = 1;
        l[1] = 2;
        for (int i = 2; i < n; i++){
            l[i] = l[i-1] + l[i-2];
        }
        return l[n-1];
    }
};