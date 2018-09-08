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

    # """
    # Get the level of tree
    # :type root: Node
    # :rtype: List[List[int]]
    # """
    def getDepth2(self, root):
        if not root:
            return 0
        queue = [root]
        count = 0
        while queue:
            next_level = []
            for node in queue:
                if node.children:
                    for child in node.children:
                        next_level.append(child)
            count += 1
            queue = next_level
        return count
        
    def maxDepth(self, root):
        # return self.getDepth(root)
        # OR
        return self.getDepth2(root)

    # """
    # Get the level of tree
    # :type root: Node
    # :rtype: List[List[int]]
    # """
    def levelOrder(self, root):
        if not root:
            return []
        queue = [root]
        res = []
        while queue:
            temp = []
            next_level = []
            for node in queue:
                temp.append(node.val)
                if node.children:
                    for child in node.children:
                        next_level.append(child)
            res.append(temp)
            queue = next_level
        return res


# EXAMPLE 1
#           1
#     3     2    4
#    5 6   7 8

# LEAF 
n5 = Node(5, None)
n6 = Node(6, None)
n7 = Node(7, None)
n8 = Node(8, None)
# DIR
n3 = Node(3, [n5, n6])
n2 = Node(2, [n7, n8])
n4 = Node(4, None)
# ROOT
n1 = Node(1, [n3, n2, n4])
# RUN SOLUTION
s = Solution()
print s.maxDepth(n1)
print s.levelOrder(n1)

# EXAMPLE 2
#          1
#      10     3 
#     5  0   6
n0 = Node(0, None)
n3 = Node(3, [n6])
n10 = Node(10, [n5, n0])
n1 = Node(1, [n10, n3])
print s.levelOrder(n1)



