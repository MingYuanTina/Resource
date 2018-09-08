// Question 
	//  66. Plus One
	//  Given a non-negative integer represented as a non-empty 
	//  array of digits, plus one to the integer.
	// You may assume the integer do not contain any leading zero, 
	// except the number 0 itself.
	// The digits are stored such that the most significant digit 
	// is at the head of the list.

// Test Cases
	// [1] --> [2]	
	// [1,2] --> [1,3]
	// [1,9,9] --> [2,0,0]
	// [9,9,9] --> [1,0,0,0]

// General Strategy
	// Edge Case 9 + 1 --> 0 and push 1 to front

// Solution
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--){
            if (digits[i] != 9){
                digits[i] += 1;
                break;
            } else {
                digits[i] = 0;
            }
        }
        if (digits[0] == 0){
            vector<int>list;
            list.push_back(1);
            for (int i = 0; i < digits.size(); i++){
                list.push_back(digits[i]);
            }
            return list;
        } else {
            return digits;
        }
        
    }
};