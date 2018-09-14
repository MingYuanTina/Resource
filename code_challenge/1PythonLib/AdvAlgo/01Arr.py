class Arr(object):
	def rotate90(self, matrix):
	# PROBLEM DESCRIPTION
	# You are given an n x n 2D matrix representing an imag
	# Rotate the image by 90 degrees (clockwise).

	# INPUT
	# type matrix: List[List[int]]
	# rtype: void 
	    res = []
	    for i in range(0, len(matrix)):
	        row = []
	        for j in range(0, len(matrix)):
	            row.append(matrix[j][i])
	        res.append(row)
	        
	    for i in range(0, len(matrix)):
	        for j in range(0, len(matrix)):
	            matrix[i][j] = res[i][j]
	        matrix[i].reverse()
	    print(matrix)

	def productExceptSelf(self, nums):
	# PROBLEM NAME
	# 238. Product of Array Except Self

	# PROBLEM DESCRIPTION
	# Given an array nums of n integers where n > 1,  return an array output 
	# such that output[i] is equal to the product of 
	# all the elements of nums except nums[i].

	# PROBLEM TYPE
	   #  """
	   #  :type nums: List[int]
	   #  :rtype: List[int]
	   #  """
		total_product = 1
		res = []
		for i in range(0, len(nums)):
		    res.append(total_product)
		    total_product *= nums[i]
		total_product = 1 
		for i in range(len(nums)-1, -1, -1):
		    res[i] *= total_product
		    total_product *= nums[i]
		return res

######################### MAIN #########################
obj = Arr()
# Rotate matrix 90 degree
matrix = [[1,2,3],[4,5,6],[7,8,9]]
obj.rotate90(matrix)

# productExceptSelf
user_input = [1,2,3,4]
print obj.productExceptSelf(user_input)







