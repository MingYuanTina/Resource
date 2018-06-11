# REFERENCE
    # 270. Closest Binary Search Tree Value
    # https://leetcode.com/problems/closest-binary-search-tree-value/description/

# DESCRIPTION
    # Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
    # Note:
    # Given target value is a floating point.
    # You are guaranteed to have only one unique value in the BST that is closest to the target.

# EXAMPLE
    # Input: root = [4,2,5,1,3], target = 3.714286
        #     4
        #    / \
        #   2   5
        #  / \
        # 1   3
    # Output: 4

# SOLUTION
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        # Base Case
        root_val = float('inf')
        left_val = float('inf')
        right_val = float('inf')
        if root:
            root_val = root.val
        else:
            return root_val
        
        # Recursive Case
        if root.left:
            left_val = self.closestValue(root.left, target)
        
        if root.right:
            right_val = self.closestValue(root.right, target)
        
        # Compute the minimum and return corresponding val
        v = abs(root_val - target)
        l = abs(left_val - target)
        r = abs(right_val - target)
        return min([root_val, left_val, right_val], key=lambda x: abs(x - target))
        
        # EXPLANATION for key=lambda
        # m = min(v, l, r)
        # if m == v:
        #     return root_val
        # elif m == l:
        #     return left_val
        # else:
        #     return right_val

# NOTE
    # use of key=lambda
    # use of float('inf')
# INPUT: [4,2,5,1,3], target = 3.714286
# DATA STRUCTURE construction
node1 = TreeNode(1)
node3 = TreeNode(3)
node5 = TreeNode(5)
node2 = TreeNode(2)
node2.left = node1
node2.right = node3
node4 = TreeNode(4)
node4.left = node2
node4.right = node5
target = 3.714286

s = Solution()
print(s.closestValue(node4, target))

