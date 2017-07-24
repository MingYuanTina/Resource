// Question
	// 344. Reverse String
	// Write a function that takes a string as input and returns the string reversed.
	// Example: Given s = "hello", return "olleh".

// Solution
class Solution {
public:
    string reverseString(string s) {
        std::reverse(s.begin(), s.end());
        return s;
    }
};