# Tree Structure
class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

	def printTree(self, root):
		# mark all visited as none
		visited = []
		queue = [root]
		while queue:
			s = queue.pop(0)
			# for all the children in tree, 
			# if not visited add to the queue:
			if s != None:
				if s.left not in visited:
					visited.append(s.left)
					queue.append(s.left)
				if s.right not in visited:
					visited.append(s.right)
					queue.append(s.right)
				#print s.val

    def getLeaf(self, root):
        res = []
        # visited intialized as empty
        visited = []
        queue = [root]
        while queue:
            s = queue.pop()
            #for all the children in the tree
            # if not visited, add to the queue
            if s != None:
                if s.right not in visited:
                    visited.append(s.right)
                    queue.append(s.right)
                if s.left not in visited:
                    visited.append(s.left)
                    queue.append(s.left)
                # add the leaf node to the tree
                if not s.left and not s.right:
                    res.append(s)
        return res
    
    def ifSimilar(self, l1, l2):
        if len(l1) != len(l2):
            return False
        else:
            for i in range(0, len(l1)):
                if l1[i].val != l2[i].val:
                    return False
        return True
		
                
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        res1 = self.getLeaf(root1)
        res2 = self.getLeaf(root2)
        if self.ifSimilar(res1, res2):
            return True
        else:
            return False

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

n3.printTree(n3)
n3.getLeaf(n3)

