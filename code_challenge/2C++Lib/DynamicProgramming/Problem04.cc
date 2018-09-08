// Question
	// 376. Wiggle Subsequence
	// A sequence of numbers is called a wiggle sequence if the differences between 
	// successive numbers strictly alternate between positive and negative. 
	// The first difference (if one exists) may be either positive or negative. 
	// A sequence with fewer than two elements is trivially a wiggle sequence.

// Test Cases
	// [] --> 0
	// [1] --> 1
	// [1,1] --> 1
	// [1,2] --> 2
	// [1,2,1] --> 3
	// [1,7,4,9,2,5] --> 6
	// [1,17,5,10,13,15,10,5,16,8] --> 7 One is [1,17,10,13,10,16,8].
	// [1,2,3,4,5,6,7,8,9] --> 2

// General Strategy
	// Check empty case
	// Counter start with 1
	// Remember prev state and compare with current state
	// Return counter

// Solution
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // Base Case
        if (!nums.size())
            return 0;
        // Other Case
        int c = 1, pre = nums[0], s = 0;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > pre && (s == -1 || c == 1)){
                c++;
                s = 1;
            }
            if (nums[i] < pre && (s == 1 || c == 1)){
                c++;
                s = -1;
            }
            pre = nums[i];
        }
        return c;
    }
};
