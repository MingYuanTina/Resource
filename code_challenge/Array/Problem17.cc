// Question
	// 268. Missing Number
	// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

// Test Cases
	// [0, 1, 3] --> 2
	// [] --> 1
	// [0,1,2] -> 3
	
// Constraint
	// Time Complexity: O(n)
	// Space Complexity: O(1)

// Solution
class Solution {
public:
    int missingNumber(vector<int>& nums) {        
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        int total = nums.size() * (nums.size() + 1)  / 2;
        return total - sum;
    }
};

class Alternative_Solution {
public:
    int missingNumber(vector<int>& nums) {        
      int result = nums.size();
      int i=0;
      for(int num:nums){
          result ^= num;
          result ^= i;
          i++;
      }
      return result;
    }
};



