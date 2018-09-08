// Question
	// 434. Number of Segments in a String
	// Count the number of segments in a string, 
	// where a segment is defined to be a contiguous sequence of non-space characters.
	// Please note that the string does not contain any non-printable characters.

// Example
	// Input: "Hello, my name is John"
	// Output: 5

// Test Cases
	// "" -> 0
	// "    " -> 0
	// "Hello" -> 1
	// "Hello, Hello" -> 2
	// "M M M M M M M " -> 2;

// Solution
class Solution {
public:
    int countSegments(string s) {
        int c = 0; 
        s.push_back(' ');
        for (int i = 1; i < s.size(); i++){
            if (s[i] == ' ' && s[i-1] != ' ')
                c++;   
        }
        return c++;
    }
};