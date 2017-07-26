// Question
	// 53. Maximum Subarray
	// Find the contiguous subarray within an array 
	// (containing at least one number) which has the largest sum.

// Testing 
	// [] --> 0
	// [-1] --> -1
	// [0,1] --> 1
	// [-1,1] --> 1
	// [1,2,3,4,5,6] -> 21
	// [-2,-4,-3,-5,4,-3] -> 4
	// [-4,-3,-5,-1] --> -1
	// [-2,1,-3,4,-1,2,1,-5,4] --> sum = 6

// General Strategy
	// Go through loop
	// When current sum is greater than max sum, reset max
	// When current sum is less than zero, reset current to 0

// Runtime
	// Time Complexity:  O(n)
	// Space Complexity: O(1)

// Solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	if (nums.size() == 0)
    		return 0;
   		bool all_neg = false;
   		for (int n : nums){
   			if (n > 0){
   				all_neg = true;
   				break;
   			}
   		}
   		if (!all_neg){
   			int max = nums[0];
   			for (int n : nums){
   				if (n > max)
   					max = n;
   			}
            return max;
   		} else {
            int max = 0, curr = 0;
   			for (int n : nums){
	    		curr += n;
	    		if (curr < 0) 
	    			curr = 0;
	    		if (curr > max)
	    			max = curr;
	    	}
            return max;
        }
    }
};
