// Question
	// 594. Longest Harmonious Subsequence
	// We define a harmonious array is an array 
	// where the difference between its maximum value 
	// and its minimum value is exactly 1.
	// Now, given an integer array, you need to 
	// find the length of its longest harmonious subsequence 
	// among all its possible subsequences.

// Test Cases
	// [] --> 0
	// [1,2,3,4] -> 1
	// [1,2,3,3,3,3] --> 4
	// [1,2,3,1,2,3] --> 4
	// [-1, -3, -2, 1, -2, 0] --> 3


// Solution
class Solution {
public:
    int findLHS(vector<int>& nums) {
        // Base Case
        if (nums.size() == 0)
            return 0;
        
        // Other Cases
        // Sort nums and store everything within hash map
        sort(nums.begin(), nums.end());
        map<int, int>l;
        for (int n : nums){
            l[n]++;
        }
        // Compare the neighbours and filter, return out max sum
        int max_s = 0;
        map<int, int>::iterator it = l.begin();
        int pre_f = it->first, pre_s = it->second;
        it++;
        for (; it != l.end(); it++){
            if (it->first - pre_f == 1 && it->second + pre_s > max_s){
                max_s = pre_s + it->second;
            }
            pre_f = it->first;
            pre_s = it->second;
        }
        return max_s;
    }
};