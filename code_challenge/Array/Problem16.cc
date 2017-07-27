// Question 
	// 88. Merge Sorted Array
	// Given two sorted integer arrays nums1 and nums2, 
	// merge nums2 into nums1 as one sorted array.
	// You may assume that nums1 has enough space (size that is greater or equal to m + n) 
	// to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.


// Solution
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0; 
        int j = 0;
        while (i < m && j < n){
            if (nums2[j] < nums1[i]){
                nums1.insert(nums1.begin() + i, nums2[j]);
                j++;
            }
            i++;
        }
        if (j >= m)
            nums1.insert(nums1.end(), nums2.begin() + j, nums2.begin() + n);
    }
};