// Question:
    // 35. Search Insert Position
    // Given a sorted array and a target value, 
    // return the index if the target is found. If not, return the index where it would be if it were inserted in order.
    // You may assume no duplicates in the array.

// Examples: 
    // [1,3,5,6], 5 → 2
    // [1,3,5,6], 2 → 1
    // [1,3,5,6], 7 → 4
    // [1,3,5,6], 0 → 0

// Solutioin:
    // Time Complexity: O(n)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        // Special Cases
        if (target == nums[nums.size() -1])
            return nums.size() - 1;
        else if (target > nums[nums.size() - 1])
            return nums.size();
        else if (target < nums[0])
            return 0;   
        
        // Other Cases
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] == target)
                index = i;
            else if (nums[i] < target && target < nums[i+1])
                index = i+1;
        }
        return index;
    }
};


// Solution Alternate:
    // Time Complexity: O(logn)
class Solution_Alternate {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        // Invariant: the desired index is between [low, high+1]
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};