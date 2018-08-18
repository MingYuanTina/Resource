# Tree Structure
class Tree:
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

	def printTree(self):
		print(self.val)
		if self.left:
			self.left.printTree()
		if self.right:
			self.right.printTree()

root = Tree(2)
root.left = Tree(1)
root.right = Tree(3)
root.printTree()

class TreeTransformation:
	def constructMaxTree(self, input_list):
		#print(input_list)
		if not input_list:
			return None

		i = input_list.index(max(input_list))
		root = Tree(input_list[i])
		root.left = self.constructMaxTree(input_list[0:i])
		root.right = self.constructMaxTree(input_list[i+1:len(input_list)])
		return root

s = TreeTransformation()
l = [3,2,1,6,0,5]
tree = s.constructMaxTree(l)
tree.printTree()


