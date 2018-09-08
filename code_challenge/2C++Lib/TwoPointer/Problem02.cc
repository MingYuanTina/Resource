// Question
	// 532. K-diff Pairs in an Array
	// Given an array of integers and an integer k, 
	// you need to find the number of unique k-diff pairs in the array. 
	// Here a k-diff pair is defined as an integer pair (i, j), 
	// where i and j are both numbers in the array and their 
	// absolute difference is k

// Testing Cases
	// Base: [], k = 0 --> Output: 0
	// Base: [1,1,1,1,1,1], k = 0 --> Output 1
	// Normal: [3, 1, 4, 1, 5], k = 2 --> Output: 2
	// Normal: [1, 2, 3, 4, 5], k = 1 --> Output: 4
	// Normal: [1, 3, 1, 5, 4], k = 0 --> Output: 1

// Note:
// The pairs (i, j) and (j, i) count as the same pair.
// The length of the array won't exceed 10,000.
// All the integers in the given input belong to the range: [-1e7, 1e7].

// Solution
	// Sort array
	// Go through all the combination of list (two pairs)
	// Check if pair existed already, otherwise store into list of vectors
	// return the list size 
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        vector<int>list;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (abs(nums[i] - nums[j]) == k){
                    if (find(list.begin(), list.end(), nums[i]) == list.end()){
                        list.push_back(nums[i]);
                    }
                }
            }
        }
        return list.size();
    }
};