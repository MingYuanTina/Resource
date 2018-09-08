// Question 
	// 14. Longest Common Prefix
	// Write a function to find the longest common 
	// prefix string amongst an array of strings.

// Test Cases	
	// [] --> ""
	// ["a"] --> "a"
	// ["abcdefg", "abcefg"] --> "abc"

// General Strategy
	// Go through array of array (string) 
	// When not matched, return substr of prefix

// Solution
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Get the shortest string length
        if (strs.size() == 0) 
            return "";
        int size = strs[0].size();
        for (string n : strs){
            if (size > n.size())
                size = n.size();
        }
        // Generate the substring of string 
        int index = size;
        for (int i = 0; i < size; i++){
            string c = strs[0].substr(i,1);
            for (int j = 0; j < strs.size(); j++){
                if (c != strs[j].substr(i,1))
                    return strs[0].substr(0, i);
            }
        }
        return strs[0].substr(0, index);
    }
};
