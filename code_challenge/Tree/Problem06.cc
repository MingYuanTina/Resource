//  654. Maximum Binary Tree
// Given an integer array with no duplicates. 
	// A maximum tree building on this array is defined as follow:
	// The root is the maximum number in the array.
	// The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
	// The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
	// Construct the maximum tree by the given array and output the root node of this tree.

// Example
// Input: [3,2,1,6,0,5]
	// Output: return the tree root node representing the following tree:
	//       6
	//     /   \
	//    3     5
	//     \    / 
	//      2  0   
	//        \
	//         1

// Test Cases
	// 1. empty array
	// 2. array with increasing order
	// 3. array with decreasing order
	// 4. array with mix
	// 5. small size array
	// 6. large array

// Implementation
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>::iterator find_max(vector<int>& nums){
        int max = nums[0];
        vector<int>::iterator i_max = nums.begin();
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
            if (*it > max) {
                max = *it;
                i_max = it;
            }  
        }    
        return i_max;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // Base Case
        if (nums.size() == 0)
            return NULL;
        // Other cases (Recursive)
        vector<int>::iterator it = find_max(nums);
        TreeNode* node = new TreeNode(*it);
        std::vector<int> left_subarray (nums.begin(), it);
        node->left = constructMaximumBinaryTree(left_subarray);
        std::vector<int> right_subarray (++it, nums.end());
        node->right = constructMaximumBinaryTree(right_subarray);
        return node;
    }
};


