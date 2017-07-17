// Question 
    // 4. Median of Two Sorted Arrays
    // There are two sorted arrays nums1 and nums2 
    // of size m and n respectively.
    // Find the median of the two sorted arrays. 
    // The overall run time complexity should be O(log (m+n)).

// Example
    // nums1 = [1, 3]
    // nums2 = [2]
    // The median is 2.0

    // nums1 = [1, 2]
    // nums2 = [3, 4]
    // The median is (2 + 3)/2 = 2.5

// General Strategy
    // Merge two arrays
    // If size is even, apply sum of two middle element divided by 2
    // If size is odd, return middle element 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num_sort;
        for (int i = 0; i < nums1.size(); i++)
            num_sort.push_back(nums1[i]);
        for (int i = 0; i < nums2.size(); i++)
            num_sort.push_back(nums2[i]);
        sort(num_sort.begin(), num_sort.end());
        double med;
        if (num_sort.size() % 2 != 0){
            med = num_sort[num_sort.size() / 2];
        } else {
            int index = num_sort.size() / 2;
            med = double((num_sort[index] + num_sort[index-1]) / 2.00);
        }
        return med;
    }
};