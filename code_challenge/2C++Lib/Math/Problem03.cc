// Question
	// 507. Perfect Number
	// We define the Perfect Number is a positive integer that is equal 
	// to the sum of all its positive divisors except itself.
	// Now, given an integer n, write a function that returns true 
	// when it is a perfect number and false when it is not.

// Test Cases	
	// 1 --> false
	// 2 --> false
	// 28 --> true (1+2+4+7++14)

// General Strategy
	// Control boundary of divisor to achieve faster runtime

// Solution
class Solution {
public:
    bool checkPerfectNumber(int num) {
        // Base Case
        if (num == 1)
            return false;
        // Other Cases
        int sum = 1, bound = num;
        for (int i = 2; i < bound; i++){
            if (num % i == 0){
                sum = sum + i + num / i;
                bound = num / i;
            }
        }
        if (sum == num)
            return true;
        else
            return false;
    }
};
