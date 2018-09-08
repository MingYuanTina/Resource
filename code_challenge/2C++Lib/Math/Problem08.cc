// Question
	// 231. Power of Two
	// Given an integer, write a function to
	// determine if it is a power of two.

// Test Cases
	// 1 --> 2 ^ 0 true
	// 2 --> false
	// 4 --> 2 ^ 2 true
	// 5 --> false
	// 8 --> 2 ^3 true

// Solution
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int c = 0;
        while (pow(2, c) <= n)
            c++;
        if (pow(2, c-1) == n)
            return true;
        return false;
    }
};

