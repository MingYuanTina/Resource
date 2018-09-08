// Question 
	// 258. Add Digits
	// Given a non-negative integer num, repeatedly add 
	// all its digits until the result has only one digit.

// Test Cases 	
	// 0 --> 0
	// 2 --> 2
	// 11 --> 2
	// 38 --> 2

// Time Complexity: O(n)
// Could you achieve O(1)?

// Solution
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10){
            int sum = 0;
            while (num / 10 != 0){
                sum += num % 10;
                num = num / 10;
            }
            num += sum;
        }
        return num;
    }
};