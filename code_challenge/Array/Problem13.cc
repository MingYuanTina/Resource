// Question
    // 41. First Missing Positive
    // Given an unsorted integer array, 
    // Find the first missing positive integer.

// Example:
    //  [] --> 1 (base)
    // [1,1] --> 2 (duplicate)
    // [-1, 0] --> 1 (negative and zero)
    // [1,2] --> 3 (after)
    // [1,3] --> 2  (middle)

// Constraint
    // Time Complexity: O(n)
    // Space Complexity: O(1)

// General Strategy
    // cout sort by sorting the index 
    // filter out negative and zero cases
    // go through list and return element where isn't stored
    // otherwise, there is no missing element in existing array
    // return max of array + 1
    // special case: when array is null, return 1

// Solution
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int>list;
        int max = 0;
        for (int i = 0; i < nums.size(); i++){
            if (list.find(nums[i]) == list.end() && nums[i] > 0)
                list[nums[i]] = 1;
            if (nums[i] > max)
                max = nums[i];
        }
        if (list.size() == 0) 
            return 1;
        for (int i = 1; i <= max; i++){
            if (list[i] != 1)
                return i;
        }
        return max + 1;
    }
};