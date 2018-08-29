class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

class GraphAlgo(object):
	def __init__(self, root):
		self.root = root

	def BFS(self):
		visited = []
		queue = [self.root]
		while queue:
			node = queue.pop(0)
			# Go through all the children of current node
			if node != None:
				print node.val
				if node.left not in visited:
					visited.append(node.left)
					queue.append(node.left)
				if node.right not in visited:
					visited.append(node.right)
					queue.append(node.right)

	def DFS2(self):
		visited = []
		stack = [self.root]
		while stack:
			node = stack.pop()
			# Go through all the children of current node
			if node != None:
				print node.val
				if node.right not in visited:
					visited.append(node.right)
					stack.append(node.right)
				if node.left not in visited:
					visited.append(node.left)
					stack.append(node.left)

	def DFS(self, node, visited):
		visited.append(node)
		# Go through all the children of current node
		if node != None:
			print node.val
			if node.left not in visited:
				self.DFS(node.left, visited)
			if node.right not in visited:
				self.DFS(node.right, visited)


# Example
#         3
#      5     1
#    6  2   9  8
#      7 4 

# LEAF
n6 = TreeNode(6)
n7 = TreeNode(7)
n4 = TreeNode(4)
n9 = TreeNode(9)
n8 = TreeNode(8)

# DIR
n2 = TreeNode(2)
n2.left = n7
n2.right = n4

n1 = TreeNode(1)
n1.left = n9
n1.right = n8

n5 = TreeNode(5)
n5.left = n6
n5.right = n2

# ROOT
n3 = TreeNode(3)
n3.left = n5
n3.right = n1

g = GraphAlgo(n3)
print "PRINT BFS"
g.BFS()

print "PRINT DFS (LOOP VERSION)"
g.DFS2()

print "PRINT DFS (RECURSION VERSION)"
g.DFS(n3, [])
