// Question:  
	// 189. Rotate Array
	// Rotate an array of n elements to the right by k steps.

// Example
	// with n = 7 and k = 3, 
	// the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

// Test Cases:
	// normal, n = size, k = 0 ==> no change
	// normal, n = size, k = size ==> no change
	// normal, n = size, k = [0, size] ==> shift as expected
	// empty, --> empty

// General Strategy 
	// size - k to find element that starts to shift

// Solution:
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++){
            nums.insert(nums.begin(), nums[nums.size()-1]);
            nums.erase(nums.begin()+nums.size()-1);
        }
    }
};

