// Question 
	// 598. Range Addition II

// Explanation
	// Given an m * n matrix M initialized with all 0's
	// and several update operations.
	// Operations are represented by a 2D array, 
	// and each operation is represented by an array with 
	// two positive integers a and b, which means M[i][j] 
	// should be added by one for all 0 <= i < a and 0 <= j < b.

// Test Cases
	// 3,3, [] --> 9
	// 3,3, [[3,3]] --> 9
	// 2,2, [[3,3]] --> 4
	// 3,3, [[3,3], [2,2], [1,1]] --> 1

// Solution
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (int i = 0; i <  ops.size(); i++){
            m = min(m, ops[i][0]);
            n = min(n, ops[i][1]);
        }
        return m * n;
    }
};