// Question
	// 541. Reverse String II
	// Given a string and an integer k, 
	// you need to reverse the first k characters 
	// for every 2k characters counting from the start of the string. 
	// If there are less than k characters left, reverse all of them. 
	// If there are less than 2k but greater than or equal to k characters, 
	// then reverse the first k characters and left the other as original.

// Example
	// Input: s = "abcdefg", k = 2
	// Output: "bacdfeg"
	// Restrictions:
	// The string consists of lower English letters only.
	// Length of the given string and k will in the range [1, 10000]

// Test Cases
		// Case 1: Equal or less than k: reverse string
		// Case 2: Equal 2k: reverse first 2k 
		// Case 3: More than 2k with less than k left

// General Strategy
    // Go through all characters
    // Every 2k is a set
		// Left over reverse the string as case 1

// Solution
class Solution {
public:
    string reverseStr(string s, int k) {
        int c = 0;
        if (s.size() < k){
            reverse(s.begin(), s.end());
            return s;
        }
        for (string::size_type i = 0; i < s.size(); i++){
            if (i < (c * 2 * k) + (k / 2)){
                int up_i = (c * 2 * k) + ((c * 2 * k) + k - i - 1);
                if (up_i >= s.size()) {
                    reverse(s.begin() + i, s.end());
                    break;
                }
                char temp = s[i];
                s[i] = s[up_i];
                s[up_i] = temp;  
            }
            if (i != 0 && (i + 1) % (2 * k) == 0)
                c++;
        }
        return s;
    }
};

class Solution_Alternate {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        string tmp, res;
        if(k > size) {
            reverse(s.begin(), s.end());
            return s;
        } else {
            for(int i = 0; i < size; i += 2 * k) {
                tmp = s.substr(i, k);
                reverse(tmp.begin(), tmp.end());
                s.replace(i, k, tmp);
            }
            return s;
        }
    }
};




