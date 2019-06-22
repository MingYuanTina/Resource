# PROBLEM SET
# Given a binary tree, solve problems using BFS

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BFS(object):
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
        : DESCRIPTION
        : BinaryTreeLevelOrderTraversal
        
        : TYPE
        : type root: TreeNode
        : rtype: List[List[int]]
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

    def maxDepth(self, root):
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
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            queue = next_level
        return res

    def findBottomLeftValue(self, root):
        """
        : DESCRIPTION
        : 513. Find Bottom Left Tree Value
        : Find the leftmost value in the last row of the tree.
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        queue = [root]
        res = 0
        while queue:
            next_level = []
            filled = False
            for node in queue:
                if not node.left and not node.right and not filled:
                    res = node.val
                    filled = True
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            queue = next_level
        return res

    def largestValues(self, root):
        """
        : DESCRIPTION
        : 515. Find Largest Value in Each Tree Row
        : Find the largest value in each row of a binary tree.
        : TYPE
        : type root: TreeNode
        : rtype: List[int]
        """
        if not root:
            return []
        queue = [root]
        res = []
        while queue:
            next_level = []
            max_node = -float("inf")
            for node in queue:
                if node.val > max_node:
                    max_node = node.val
                # add children of current node
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            queue = next_level
            res.append(max_node)
        return res

    def rightSideView(self, root):
        """
        : DESCRIPTION:
        : 199. Binary Tree Right Side View
        : return the values of the nodes you can see ordered from top to bottom
        : TYPE
        : type root: TreeNode
        : rtype: List[int]
        """
        if not root:
            return []
        queue = [root]
        res = []
        while queue:
            # get the right most value
            temp = queue[len(queue)-1]
            res.append(temp.val)
            # traverse next level
            nl = []
            for node in queue:
                if node.left:
                    nl.append(node.left)
                if node.right:
                    nl.append(node.right)
            queue = nl
        return res

    def zigzagLevelOrder(self, root):
        """
        : DESCRIPTION
        : 103. Binary Tree Zigzag Level Order Traversal
        : return the zigzag level order traversal of its nodes' values. 
        : (ie, from left to right, then right to left for the next level and alternate between)
        : TYPE
        : type root: TreeNode
        : rtype: List[List[int]]
        """
        if not root:
            return []
        leftToRight = True
        queue = [root]
        res = []
        while queue:
            temp = []
            nl = []
            for node in queue:
                temp.append(node.val)
                if node.left:
                    nl.append(node.left)
                if node.right:
                    nl.append(node.right)
            if not leftToRight:
                temp.reverse()   
                leftToRight = True
            else:
                leftToRight = False
            res.append(temp)
            queue = nl
        return res

    def pruneTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        # subtree is removed when either children == None or contains all zero and node.val = 0
        # such contains satisfies, then return true, else return false
        # a child is deleted when either left or right tree is none 
        def pruneTreeHelper(root):
            if root == None:
                return True
            else:
                leftTree = pruneTreeHelper(root.left)
                rightTree = pruneTreeHelper(root.right)
                if root.val == 0 and leftTree and rightTree:
                    return True
                if leftTree:
                    root.left = None
                if rightTree:
                    root.right = None
                return False 
        temp = pruneTreeHelper(root)
        return root

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
s = BFS()
print s.levelOrderBottom(n3)        # EXPECTED [[15, 7], [9, 20], [3]]
print s.minDepth(n3) 				# EXPECTED 2
print s.maxDepth(n3) 				# EXPECTED 3
print s.largestValues(n3)			# EXPECTED [3, 20, 15]
print s.rightSideView(n3)			# EXPECTED [3, 20, 7]
print s.zigzagLevelOrder(n3)		# EXPECTED [[3], [20, 9], [15, 7]]


