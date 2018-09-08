// Question
	// 34. Search for a Range
	// Given an array of integers sorted in ascending order, 
	// find the starting and ending position of a given target value.
	// Your algorithm's runtime complexity must be in the order of O(log n).

// Example
	//  [5, 7, 7, 8, 8, 10],  8 ==> [3, 4]
	// 	[], 0 ==> [-1, -1]
	// 	[5,7,7,8, 10], 8 ==> [3,3]

// Solution
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = -1, end = -1, before_len = 0, after_len = 0, l = 0, r = nums.size() - 1;
        // Binary search
        while (l <= r){
            int m = l + (r - l) / 2;
            if (nums[m] == target){
                begin = m;
                break;
            } else if (nums[m] < target){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (begin == -1){
            vector<int> empty_res = {-1, -1};
            return empty_res;
        }
        // Calculate range;
        while (begin-before_len >= 0 && nums[begin-before_len]  == target)
            before_len += 1;
        while (begin+after_len < nums.size() && nums[begin+after_len] == target)
            after_len += 1;
        end = begin + (after_len - 1);
        begin = begin - (before_len - 1);
        vector<int> res = {begin, end};
        return res;
    }
};