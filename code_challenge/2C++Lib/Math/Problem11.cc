// Question
	// 263. Ugly Number
	// Write a program to check whether a given number is an ugly number.
	// Ugly numbers are positive numbers whose prime factors only include 
	// 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since 
	// it includes another prime factor 7.
	// Note that 1 is typically treated as an ugly number.

// Test Cases
	// 0 -> false
	// 1 -> true
	// 2 --> true
	// 4 --> true
	// 3 --> true 
	// 6 --? true
	// 5 --> true
	// 10 --> true
	// 2 * 3 * 5 --> true
	// 2 * 3 * 5 * 7 --> true

// Solution
class Solution {
public:
    bool isUgly(int num) {
        // Base Case
        if (num == 0)
            return false;
        
        // Other Cases
        while (num % 2 == 0)
            num = num / 2;
        while (num % 3 == 0)
            num = num / 3;
        while (num % 5 == 0)
            num = num / 5;
        
        if (num == 1)
            return true;
        else 
            return false;
    }
};