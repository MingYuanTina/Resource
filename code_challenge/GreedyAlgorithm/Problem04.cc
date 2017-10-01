// Question 
	// 55. Jump Game
	// Given an array of non-negative integers, 
	// you are initially positioned at the first index of the array.
	// Each element in the array represents your maximum jump length at that position.
	// Determine if you are able to reach the last index

// Test Cases
	// A = [2,3,1,1,4], return true.
	// A = [3,2,1,0,4], return false.
	// A = [3,0,0,1,4], return true
	// A = [3,0,0,0,4], return false 
	// A = [5,0,0,1,0,4], return true

// Idea:
	// Taking the maximum at each time for each index
	// If reach zero after jump, decrement and try again
	// Otherwise, continue

// Implementation
class Solution {
public:
	bool canJump(vector<int>& nums) {
		// Base Case
		if (nums.size() == 0 || nums.size() == 1){
			return true;
		}
		// Other Cases
		int i = 0;
		while (i < nums.size()){
			if (nums[i] == 0)
				return false;
			i += nums[i];
			if (nums[i] != 0){
				// do nothing
			} else {
				i -= nums[i];
				nums[i]--;
			}
		}
		return true;
	}
};