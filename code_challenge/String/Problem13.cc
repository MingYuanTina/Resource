// Question 
	// 58. Length of Last Word
	// Given a string s consists of upper/lower-case alphabets 
	// and empty space characters ' ', return the length of last word in the string.
	// If the last word does not exist, return 0.

// Test Cases
	// s = "Hello World" --> 5
	// s = " " -> 0
	// s = " a  " -> 1
	// s = " a " -> 1

// General Strategy:
	// Whenever there is space with index not equal to zero
	// return index
	// otherwise return index as zero

// Solution
class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = 0;
        for (int i = s.size() - 1; i >= 0; i--){
            if (index != 0 && s.substr(i,1) == " "){
                break;
            }
            if (s.substr(i,1) != " "){
                index++;
            }
        }
        return index;
    }
};