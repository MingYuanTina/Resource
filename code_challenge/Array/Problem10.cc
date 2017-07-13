// Question  26. Remove Duplicates from Sorted Array
	// Given a sorted array, remove the duplicates in place 
	// such that each element appear only once and return the new length.

// Example,
 	// Given input array nums = [1,1,2],
	// Your function should return length = 2, with the first two elements 
	// of nums being 1 and 2 respectively.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int i = 0;
        while (i < nums.size() - 1){
            if (nums[i+1] == nums[i])
            	nums.erase(nums.begin()+i);
            else 
               i++;
        }
        return nums.size();
    }
};