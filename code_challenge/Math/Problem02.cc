// Question
	// 326. Power of Three
	// Given an integer, write a function to 
	// determine if it is a power of three.
	//  Could you do it without using any loop / recursion?

// Test
	// 0 --> 0
	// 3 --> false
	// 5 --> false
	// 9 --> false
	
// Solution
class Solution {
public:
    bool isPowerOfThree(int n) {
        long long num = 3;
        while (num < n){
            num *= 3;
        }
        if (num == n && n != 0 || n == 1)
            return true;
        else 
            return false;
        
    }
};
