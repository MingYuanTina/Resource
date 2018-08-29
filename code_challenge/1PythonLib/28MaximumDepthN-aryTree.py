# PROBLEM
# Given a n-ary tree, find its maximum depth.
# The maximum depth is the number of nodes along the longest path 
# from the root node down to the farthest leaf node.
# The depth of the tree is at most 1000.
# The total number of nodes is at most 5000.

# SOLUTION
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children

class Solution(object):
    def getDepth(self, node):
        if node == None:
            return 0
        if node.children == None:
            return 1
        # Go through all children of current node and compare
        max_depth = 0
        for temp in node.children:
            cur_len = self.getDepth(temp)
            if cur_len > max_depth:
                max_depth = cur_len
        return max_depth + 1
        
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        return self.getDepth(root)


# EXAMPLE
#           1
#      3    2    4
#    5   6

# LEAF 
n5 = Node(5, None)
n6 = Node(6, None)
# DIR
n3 = Node(3, [n5, n6])
n2 = Node(2, None)
n4 = Node(4, None)
# ROOT
n1 = Node(1, [n3, n2, n4])
# RUN SOLUTION
s = Solution()
print s.maxDepth(n1)

