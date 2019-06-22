# permutation -> n!
# recursion --> 

# [1,2,3]
# 3*2*1

# [1,2,3]
# res.[1] --> permute([2,3]) --> [2, permute[3]] --> [2,3]
         #--> permute(2,3) --> [3, permute[2]] --> [3,2]
# [1, permute([2,3])] --> [[1], ([2,3],[3,2])] --> [[1,2,3], [1,3,2]]

class Solution(object):
	def __init__(self):
		self.res = []

	def get_result(self):
		print self.res

	def calculate_permutation(self, nums):
		if len(nums) == 1 or not len(nums):
			return [nums]
		else:
			res = []
			# Iterating through nums as each number can appearing at the first position
			for i in range(len(nums)):
				for subset in self.calculate_permutation(nums[:i] + nums[i+1:]):
					res.append([nums[i]]+subset)
			self.res = res
			return res


	# permutation without repetitation
	# formula -> n!/(n-r)!
	# [1,2,3]
	# [[1],  permute([2,3], 1)  -> [[2], permute[]] -> [[2]]
      	#    permute([3], 1)    -> [[3], permute[]] -> [3]
     # [[2], permute([3], 1)
	def calculate_combination(self, nums, k):
		res = []
		if k == 1:
			for i in range(len(nums)):
				res.append([nums[i]])
		else:
			for i in range(0, len(nums)-k+1):
				subsets = self.calculate_combination(nums[i+1:], k-1)
				for subset in subsets:
					res.append([nums[i]]+subset)
			self.res = res
		return res
	


def main():
	user_input = [1,2,3]
	s = Solution()
	s.calculate_permutation(user_input)
	s.get_result()
	s.calculate_combination(user_input, 2)
	s.get_result()

main()


