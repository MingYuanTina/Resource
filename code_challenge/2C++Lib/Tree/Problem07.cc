// Question
// 671. Second Minimum Node In a Binary Tree
	// Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. 
	// If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.
	// Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
	// If no such second minimum value exists, output -1 instead.

class Solution {
public:
    map<int, int> Traverse(TreeNode* root, map<int, int>list){
        if (!root)
            return list;
        list[root->val] = 0;
        list = Traverse(root->left, list);
        list = Traverse(root->right, list);
        return list;
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        map<int, int>list;
        map<int, int>temp = Traverse(root, list);
        
        // Base Case
        if (temp.size() == 1){
            return -1;
        }
        // Other Case
        map<int, int>::iterator it = temp.begin();
        it++;
        return it->first;
    }
};