# PROBLEM
# Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
# (ie, from left to right, level by level from leaf to root).

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        res = self.levelOrder(root)
        res.reverse()
        return res
        

    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        queue = [root]
        res = []
        while queue:
            temp = []
            next_level = []
            for node in queue:
                temp.append(node.val)
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            res.append(temp)
            queue = next_level
        return res

    def minDepth(self, root):
        """
        : DESCRIPTION
        : The minimum depth is the number of nodes along the shortest path 
        : from the root node down to the nearest leaf node.
        
        : TYPE
        : type root: TreeNode
        : rtype: int
        """
        if not root:
            return 0
        queue = [root]
        res = 0
        while queue:
            next_level = []
            res += 1
            for node in queue:
                if node.left == None and node.right == None:
                    return res
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            queue = next_level
        return res


# EXAMPLE
#         3
#       9   20
#          15 7
# LEAF
n15 = TreeNode(15)
n7 = TreeNode(7)
# DIR
n9 = TreeNode(9)
n20 = TreeNode(20)
n20.left = n15
n20.right = n7
# ROOT
n3 = TreeNode(3)
n3.left = n9
n3.right = n20
# RUN SOLUTION
s = Solution()
print s.levelOrderBottom(n3)
print s.minDepth(n3) # EXPECTED 2

