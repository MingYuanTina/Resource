// Question
	// 349. Intersection of Two Arrays
	// Given two arrays, write a function to compute their intersection
	// Acceptance Creteria
	// Each element in the result must be unique.
	// The result can be in any order.

// Test Cases:
	// [], [] --> []
	// [1,2,3,4,5], [] --> []
	// [1,2,3,4,5], [2,2] --> []
	// [1,2,2,3,4,5], [2,2] --> [2]
	// [1,2,3,4,5], [1,2,3,4,5] --> [1,2,3,4,5]
	// [1,2,3,4,5], [2,5] --> [2,5]

// Solution
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      vector<int>l;
      if (nums1.size() == 0 || nums2.size() == 0){
        return l;
      }
      for (int i = 0; i < nums1.size(); i++){
        for (int j = 0; j < nums2.size(); j++){
          if (nums1[i] == nums2[j]){
            if (find(l.begin(), l.end(), nums1[i]) == l.end()){
              l.push_back(nums1[i]);    
            }  
          }
        }
      }
      return l;
    }
};

