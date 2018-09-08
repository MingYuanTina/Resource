// Question
	// 9. Palindrome Number
	// Determine whether an integer is a 
	// palindrome. Do this without extra space.

// Test Cases
	// -1 --> false
	// 1 --> true
	// 11 --> true
	// 12321 --> true

// Solution
class Solution {
public:
    bool isPalindrome(int x) {
        // False case
        if (x < 0)
            return false;
        // Positive case
        stringstream ss;
        ss << x;
        string temp = ss.str();
        for (int i = 0; i < temp.length() / 2; i++){
            if (temp[i] != temp[temp.length() - i - 1])
                return false;
        }
        return true;
    }
};