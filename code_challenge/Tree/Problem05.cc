// Question
	// 104. Maximum Depth of Binary Tree
	// Given a binary tree, find its maximum depth.
	// The maximum depth is the number of nodes along 
	// the longest path from the root node down to the farthest leaf node.

// Solution
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
    int maxDepth(TreeNode* root) {
        if (root){
            int left, right;
            left = 1 + maxDepth(root->left);
            right = 1 + maxDepth(root->right);
            return max(left, right);
        } else {
            return 0;
        }
    }
};