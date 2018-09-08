// Question
	// 350. Intersection of Two Arrays II
	// Given two arrays, write a function to 
	// compute their intersection

// Test Cases
	// [],[] --> []
	// [1,2,3,4],[] --> []
	// [1,2,3,4,5],[1,2,3,4,5] --> [1,2,3,4,5]
	// [1,2,2,1], [2,2] --> [2,2]
	// [1,2,3,4,5],[2,5] --> [2,5]

// Note:
// Each element in the result should appear as 
// many times as it shows in both arrays.
// The result can be in any order.

// Solution
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>l;
        for (int n : nums1){
            for (int i = 0; i < nums2.size(); i++){
                if (n == nums2[i]){
                    l.push_back(n);
                    nums2.erase(nums2.begin()+i);
                    break;
                }
            }
        }
        return l;
    }
};

