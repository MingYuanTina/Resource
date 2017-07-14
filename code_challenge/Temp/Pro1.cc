// Question:
    // 
    // Given an integer array, 
    // find three numbers whose product is maximum 
    // and output the maximum product.

// Example 
    // Input: [1,2,3]
    // Output: 6
    // Example 2:
    // Input: [1,2,3,4]
    // Output: 24

// Note:
    // The length of the given array will be in range [3,104] 
    // and all elements are in the range [-1000, 1000].
    // Multiplication of any three numbers in the input 
    // won't exceed the range of 32-bit signed integer.

// Test:
    // 

// Solution: 
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int>neg_nums;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < 0)
                neg_nums.push_back(nums[i]);
        }
        int max_neg = 0, max_pos = 0;
        if (neg_nums.size() >= 2)
            max_neg = neg_nums[0] * neg_nums[1] * nums[nums.size() -1];
        max_pos = nums[nums.size()-3] * nums[nums.size()-2] * nums[nums.size()-1]; 
        return max_neg >= max_pos ? max_neg : max_pos;
    }
};