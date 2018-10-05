# PROBLEM SET
# Given a problem, solve it using DFS
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class DFS(object):
	def runDFS(self, node):
		if node != None:
			print node.val
			if node.left:
				self.runDFS(node.left)
			if node.right:
				self.runDFS(node.right)

	def binaryTreePaths(self, root):
	        """
	        : DESCRIPTION
	        : 257. Binarsy Tree Paths
	        : Given a binary tree, return all root-to-leaf paths.
	        
	        : TYPE
	        : type root: TreeNode
	        : rtype: List[str]
	        """
	        def getPaths(node, paths, pre_path):
	            if node != None:
	                if pre_path == "":
	                    cur_path = str(node.val)
	                else:
	                    cur_path = pre_path + "->" + str(node.val)
	                if node.left != None:
	                    paths = getPaths(node.left, paths, cur_path)
	                if node.right != None:
	                    paths = getPaths(node.right, paths, cur_path)
	                if not node.left and not node.right:
	                    paths.append(cur_path)
	            return paths
	    
	        paths = []
	        pre_path = ""
	        return getPaths(root, paths, pre_path)

	def hasPathSum(self, root, sum):
	        """
	        : DESCRIPTION
	        : 112. Path Sum
	        : Given a binary tree and a sum, determine if the tree has a root-to-leaf 
	        : path such that adding up all the values along the path equals the given sum.
	        :
	        : TYPE
	        : type root: TreeNode
	        : type sum: int
	        : rtype: bool
	        """
	        def getPaths(node, paths, pre_sum):
	            if node != None:
	                cur_sum = pre_sum + node.val
	                if node.left: 
	                    paths = getPaths(node.left, paths, cur_sum)
	                if node.right: 
	                    paths = getPaths(node.right, paths, cur_sum)
	                if not node.left and not node.right:
	                    paths.append(cur_sum)
	            return paths
	    
	        paths = getPaths(root, [], 0)
	        for path in paths:
	            if path == sum: return True
	        return False

	def flatten(self, root):
	        """
	        : DESCRIPTION
	        : 114. Flatten Binary Tree to Linked List
	        : Given a binary tree, flatten it to a linked list in-place.
	        :
	        : TYPE
	        : type root: TreeNode
	        : rtype: void Do not return anything, modify root in-place instead.
	        :
	        : EXAMPLE
	        :    1
	        :   / \
	        :  2   5
	        : / \   \
	        :3   4   6
	        : EXPECTED
	        :1
	        : \
	        :  2
	        :   \
	        :    3
	        :     \
	        :      4
	        :       \
	        :        5
	        :         \
	        :          6
	        """
	        def getFlattenList(node, paths):
	            if node != None:
	                paths.append(node.val)
	                if node.left:
	                    paths = getFlattenList(node.left, paths)
	                if node.right:
	                    paths = getFlattenList(node.right, paths)
	            return paths
	    
	        if not root: 
	            return root
	        paths = getFlattenList(root, []) 
	        paths.pop(0)
	        root.left = None
	        for path in paths:
	            temp = TreeNode(path)
	            root.right = temp
	            root = temp
	        
# EXAMPLE
#         3
#       9   20
#     15 7
#    6

# LEAF
n6 = TreeNode(6)
n7 = TreeNode(7)
n20 = TreeNode(20)
# DIR
n15 = TreeNode(15)
n15.left = n6
n9 = TreeNode(9)
n9.left = n15
n9.right = n7
# ROOT
n3 = TreeNode(3)
n3.left = n9
n3.right = n20

s = DFS()
s.runDFS(n3)
print s.binaryTreePaths(n3)  		# EXPECTED ['3->9->15->6', '3->9->7', '3->20']
print s.hasPathSum(n3, 19)

s.flatten(n3)
print s.binaryTreePaths(n3)
