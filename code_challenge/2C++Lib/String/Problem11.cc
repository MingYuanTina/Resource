// Question 
	// 345. Reverse Vowels of a String
	// Write a function that takes a string as input and reverse only the vowels of a string.

// Test Cases
	// s = "hello", return "holle".
	// s = "leetcode", return "leotcede".

// Constraint
	// Not specified

// Solution
class Solution {
public:
    string reverseVowels(string s) {
        string list[10] = {"a", "e", "i", "o", "u", "A", "E", "I", "O", "U"};
        vector<string>l;
        for (int i = 0; i < s.size(); i++){
            for (int j = 0; j < sizeof(list)/sizeof(string); j++){
                if (s.substr(i, 1) == list[j]){
                    cout << list[j] << endl;
                    l.push_back(list[j]);
                    break;
                }
            }
        }
        int index = 0;
        for (int i = s.size() - 1; i >= 0; i--){
            for (int j = 0; j < sizeof(list)/sizeof(string); j++){
                if (s.substr(i, 1) == list[j]){
                    cout << list[j] << endl;
                    s.replace(i, 1, l[index]);
                    index++;
                    break;
                }
            }
        }
        return s;
    }
};