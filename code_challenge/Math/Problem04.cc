// Question
	// 633. Sum of Square Numbers
	// Given a non-negative integer c, your task is to decide
	// whether there're two integers a and b such that a2 + b2 = c

// Test Cases	
	// 1 --> false
	// 2 --> false
	// 5 --> true (1^2 + 2^2)
	// 6 --> false

// General Strategy
	// How do you loop through all the combination of number?
		// Given n, if you want to take all combination of number O(n^2)
		// If there time requirement for this question?
			// If not require less than O(n^2) --> done
			// Otherwise --> any assumption helps
				// CALCULATE COUNTERPARTS and VERIFY: O(n)

// Solution
class Solution {
public:
    bool judgeSquareSum(int c) {
        int bound = sqrt(c);
        for (int i = 0; i <= sqrt(c); i++){
            int left = sqrt(c - i * i);
            if (left * left + i * i == c)
                return true;
            
        }
        return false;
    }
};
