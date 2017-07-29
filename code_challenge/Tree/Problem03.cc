// Question
	// 101. Symmetric Tree
	// Given a binary tree, check whether 
	// it is a mirror of itself (ie, symmetric around its center).

// Testing Cases:
// Null -> true
// [1] -> true
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3


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
    bool isSym(TreeNode *left, TreeNode *right){
        if (left && right){
            //cout << left->val << right->val << endl;
            if (left->val != right->val){
                return false;
            } else {
                bool check_left, check_right;
                check_left = isSym(left->left, right->right);
                check_right = isSym(left->right, right->left);
                if (check_left && check_right){
                    return true;
                } else {
                    return false;
                } 
            }
        } else if (!left && !right) {
            return true;
        } else {
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if (!root){
            return true;
        } else {
            if (root->left && root->right){
                cout << "test" << endl;
                return isSym(root->left, root->right);
            } else if (!root->left && !root->right) {
                return true;
            }else {
                return false;
            }
        }
    }
};