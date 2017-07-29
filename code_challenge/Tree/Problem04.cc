// Question
	// 501. Find Mode in Binary Search Tree
	// Given a binary search tree (BST) with duplicates, find all the mode(s) 
	// (the most frequently occurred element) in the given BST.
	// Assume a BST is defined as follows:
	// The left subtree of a node contains only nodes 
	// with keys less than or equal to the node's key.
	// The right subtree of a node contains only nodes 
	// with keys greater than or equal to the node's key.
	// Both the left and right subtrees must also be binary search trees.
	
// Test Cases
	// [] -> [] (Empty)
	// [1] -> [1]	 (Base)
	// [1,2,null,2] -> [2] (Single Mode)
	// [1,2,null,2,3,3,4] -> [2,3] (Multiple Mode)

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
#include <algorithm>
class Solution {
public:
    int getList(TreeNode* root, map<int, int> &l){
        if (!root){
            return 0;
        } else {
            l[root->val]++;
            return max(l[root->val], max(getList(root->left, l), getList(root->right, l)));
        }
    }
    vector<int> findMode(TreeNode* root) {
        map<int, int>l;
        vector<int>mode;
        int max = getList(root, l);
        
        for (map<int, int>::iterator it = l.begin(); it != l.end(); it++){
            if (it->second == max){
                mode.push_back(it->first);
            }
        }
        return mode;
    }
};