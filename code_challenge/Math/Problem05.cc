// Question
	// 441. Arranging Coins
	// You have a total of n coins that you want to 
	// form in a staircase shape, where every k-th row must have exactly k coins.
	// Given n, find the total number of full staircase rows that can be formed.	
	// n is a non-negative integer and fits within the range of a 32-bit signed integer.

// Explanation
// n = 5
// The coins can form the following rows:
// ¤
// ¤ ¤
// ¤ ¤
// Because the 3rd row is incomplete, we return 2.

// Test Cases
	// 1 --> 1
	// 2 --> 1
	// 3 --> 2
	// 4 --> 2

// General Strategy
	// counter = number of staircase

// Solution
class Solution {
public:
    int arrangeCoins(int n) {
        int c = 0;
        while (n >= 0){
            c += 1;
            n -= c;
        }
        return c - 1;
    }
};
