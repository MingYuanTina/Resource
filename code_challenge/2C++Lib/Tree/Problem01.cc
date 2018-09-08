// Question
	// Given two binary trees, write a function 
	// to check if they are equal or not.
	// Two binary trees are considered equal 
	// if they are structurally identical and 
	// the nodes have the same value.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val == q->val){
            bool check_left, check_right;
            check_left = isSameTree(p->left, q->left);
            check_right = isSameTree(p->right, q->right);
            if (check_left && check_right){
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};