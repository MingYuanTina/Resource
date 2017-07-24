// Question
	// 448. Find All Numbers Disappeared in an Array
	// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), 
	// some elements appear twice and others appear once.
	// Find all the elements of [1, n] inclusive that do not appear in this array.

// Constraint
	// Time Complexity: O(n)
	// Space Complexity: O(1)

// Test Cases
	// Base Case: [] --> []
	// Duplicate Case: [4,3,2,7,8,2,3,1] --> [5,6]

// General Strategy
	// Base Case: Check if null, return null
	// Otherwise: use count sort and return list stored

// Implementation
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> miss_list;
        
        // Base Cases
        if (nums.size() == 0){
            return miss_list;
        }
        
        // Other Cases
        int list [nums.size()] = { 0 };
        for (int n : nums){
            list[n-1] += 1;
        }
        for (int i = 0; i < nums.size(); i++){
            if (list[i] == 0){
                miss_list.push_back(i + 1);
            }
        }
        return miss_list;
    }
};

	

