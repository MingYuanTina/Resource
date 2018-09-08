// Question:
      // 485  Max Consecutive Ones
      // Given a binary array, 
      // find the maximum number of consecutive 1s in this array.

// Example:
      // Input: [1,1,0,1,1,1]
      // Output: 3
      // Explanation: The first two digits or the last three digits are consecutive 1s.
      // The maximum number of consecutive 1s is 3.

// Constraints: 
      // The input array will only contain 0 and 1.
      // The length of input array is a positive integer and will not exceed 10,000

// Test Cases:
      // Empty array ==> 0
      // [1] ==> 1
      // [0] ==> 0
      // [1,1] ==> 2
      // [1,1,0,1,1,1] ==> 3
      // [1,0,1,0,1,1,0,0,1,1,1,0] ==> 3

// Solution 
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, max = 0;
        vector<int> list;
        while (i < nums.size()){
            int count = 0;
            while (i < nums.size() && nums[i] != 0){
                i++;
                count++;
            }
            if (count > max){
                max = count;
            }
            i++;
        }   
        return max;
    }
};

