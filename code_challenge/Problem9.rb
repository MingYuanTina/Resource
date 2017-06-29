# Definition for a binary tree node
class TreeNode
	attr_accessor :val, :left, :right
	def initialize(val)
		 @val = val
		 @left, @right = nil, nil
   end
 end

# @param {TreeNode} t1
# @param {TreeNode} t2
def merge_trees(t1, t2)
	# case 4: base case none exists
	if t1 == nill && t2 == nill
		nil
	end

	newNode = TreeNode.new(nil)

	# split into four cases
	# case 1: both exists
	if t1 != nill && t2 != nil
		newNode.val = t1.val + t2.val
		newNode.left = merge_trees(t1.left, t2.left)
		newNode.right = merge_trees(t1.right, t2.right)
	# case 2: t1 exists
	elsif t2 == nil
		newNode.val = t1.val
		newNode.left = merge_trees(t1.left, t2)
		newNode.right	 = merge_trees(t1.right, t2)
	# case 3: t2 exists
	elsif t3 == nil
		newNode.val = t2.val
		newNode.left = merge_trees(t1, t2.left)
		newNode.right = merge_trees(t1, t2.right)
	end
end