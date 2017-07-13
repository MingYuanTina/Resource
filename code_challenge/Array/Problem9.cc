// Question
// 27. Remove Element

// Given an array and a value, remove all instances of that value in place and return the new length.
	// Do not allocate extra space for another array, you must do this in place with constant memory.
	// The order of elements can be changed. It doesn't matter what you leave beyond the new length.

// Example
	// Given input array nums = [3,2,2,3], val = 3
	// Your function should return length = 2, with the first two elements of nums being 2.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c = 0;
        while (c < nums.size()){
            if (nums[c] == val)
                nums.erase(nums.begin()+c);
            else
                c++;  
        }
        return nums.size();
        
    }
};