// Question
	//  7. Reverse Integer
	// Reverse digits of an integer.
	// NOTE: 
	// The input is assumed to be a 32-bit signed integer. 
	// Your function should return 0 when the reversed integer overflows.

// Test Cases
	// 123 -->  321
	//  -123 --> -321
	// long number --> 0
	// 0 --> 0

// Solution
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while (x){
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res > INT_MAX || res < INT_MIN)
            return 0;
        return res;        
    }
};