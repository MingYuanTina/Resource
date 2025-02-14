// Question 389. Find the Difference
	// Given two strings s and t which consist of only lowercase letters.
	// String t is generated by random shuffling string s and 
	// then add one more letter at a random position.
	// Find the letter that was added in t.

// Test Cases
	// "", "" --> ""
	// "a", "aa" --> 'a'
	// "abcde", "edacb" --> "e"
	// "abcd", "abcde" --> "e"

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<char>list;
        for (int i = 0; i < s.length(); i++)
            list.push_back(s[i]);
        for (int i = 0; i < t.length(); i++){
            if (find(list.begin(), list.end(), t[i]) == list.end())
                return t[i];
            else
                list.erase(find(list.begin(), list.end(), t[i]));
        }
    }
};

