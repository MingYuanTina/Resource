// Question 
	//  392. Is Subsequence
	// Given a string s and a string t, check if s is subsequence of t.
	// You may assume that there is only lower case English letters in both s and t. 
	// t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
	// A subsequence of a string is a new string which is formed from the original string 
	// by deleting some (can be none) of the characters without disturbing the relative positions 
	// of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

// Test Cases
	// s = "abc", t = "ahbgdc" --> true
	// s = "axc", t = "ahbgdc" --> false

// Implementation
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0)
            return true;
        int i = 0, c = 0, j = 0;
        while (j < t.length()){
            if (s[i] == t[j]){
                i++;
                if (i == s.length())
                    return true;
            }
            j++;
        }
        return false;
    }
};