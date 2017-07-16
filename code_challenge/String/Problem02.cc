// Question 
	// 551. Student Attendance Record I
	// 	You are given a string representing an attendance record for a student. 
	//  The record only contains the following three characters:
	// 'A' : Absent, 'L' : Late, 'P' : Present.
	// A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
	// You need to return whether the student could be rewarded according to his attendance record

// Sample Example:
	// Input: "PPALLP", Output: True
	// Input: "PPALLL", Output: False

// Test Cases
	// This question have a few cases
	// When A > 1, return false
	// When L > 2 && L is continuous, return false
	// When L > 2 && L is not continuous, return true
	// All other cases, return true

// General Strategy:
	// Set counter for A, when A > 1, return false immediately
	// Set index list for L and when there is continuous, return false immediately
	// Otherwise, return true;

// Solution
class Solution {
public:
    bool checkRecord(string s) {
        int i, ab = 0;
        vector<int>list; 
        for (string::iterator it = s.begin(); it != s.end(); ++it){
            if (*it == 'A')
                ab++; 
            if (ab > 1)
                return false;
            if (*it == 'L'){  
                 list.push_back(i);
            }
            i++;
        }
        if (list.size() >= 3){
            for (int i = 0; i < list.size() - 2; i++){
                if (list[i+1] - list[i] == 1 && list[i+2] - list[i+1] == 1){
                    return false;
                }
            }
        }
        return true;
    }
};