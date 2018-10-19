# October 13th, 2018

# *********************************** Problem 1 ***********************************
# Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], 
# 	we split the array into some number of "chunks" (partitions), 
# 	and individually sort each chunk.  
#	After concatenating them, the result equals the sorted array.

# Iterating through each number of arr
# Creating self-contained chunks with checking if next arr[i] consecutive nums
# can be fitted into the self-contained chunk
# 	If yes, add to self-contained list
# 	If no, keep expanding the list
def maxChunksToSorted(arr):
	total = 0 # total number of chunks

   	# Iterating through all the elements in the arr
   	i = 0
   	while i < len(arr):
   		# Creating self-contained chunks
   		chunks = [-1 for k in range(i, arr[i])]
   		chunks.append(arr[i])
   		cl = len(chunks)
   		k = i+1
   		while k < i+cl:
   			if arr[k] >= i+len(chunks):
   				for g in range(i+cl, arr[k]):
   					chunks.append(-1)
   					cl += 1
   				chunks.append(arr[k])
   				cl += 1
   			k += 1
   		i += len(chunks)
   		total += 1
   	return total

l1 = [0,1,2,3,4] # 5
l2 = [4,2,3,1,0] # 1
l3 = [2,1,3,4,0] # 1
l4 = [2,0,1,3,4] # 3
l5 = [1,2,3,4,5,0] # 1
print maxChunksToSorted(l1)
print maxChunksToSorted(l2)
print maxChunksToSorted(l3)
print maxChunksToSorted(l4)
print maxChunksToSorted(l5)

# *********************************** Problem 2 ***********************************
# 78. Subsets
# Given a set of distinct integers, nums, return all possible subsets (the power set).
# Note: The solution set must not contain duplicate subsets.

# Takes a list of numbers and given size of subset (k)
# Recusively extracting all the number combination in the list
# [1,2,3], 2 --> [1, [2,3]], 1 --> [[1,2], [2,3]], 0
# 	[2,3], 2 --> [2, [3]], 1 --> [[2,3]], 0
def get_combination(nums, k):
	res = []	# result stores all the subset combination
	if k == 1:	# base case
		for i in range(len(nums)):
			res.append([nums[i]])
	else: 		# other case
		for i in range(len(nums)-k+1):
			subsets = get_combination(nums[i+1:], k-1)
			for subset in subsets:
				res.append([nums[i]] + subset)
	return res

def subsets(nums):
	res = []
	res.append([])
	for i in range(1, len(nums)+1):
		res += get_combination(nums, i)
	return res

# def subsets(self, nums):
#     nums.sort()
#     result = [[]]
#     for num in nums:
#         result += [i + [num] for i in result]
#     return result
n1 = [1,2,3]
print subsets(n1)

# *********************************** Problem 3 ***********************************
# 611. Valid Triangle Number
	# Given an array consists of non-negative integers, 
	# your task is to count the number of triplets chosen from the array 
	# that can make triangles if we take them as side lengths of a triangle.

def triangleNumber(nums):
	subsets = get_combination(nums, 3)
	for subset in subsets:
		subset.sort()
		x = subset[0]
		y = subset[1]
		z = subset[2]
		if not (x + y > z) and not (z - y < x):
			return False
	return True


# *********************************** Problem 4 ***********************************
# 39. Combination Sum
# Graph
# Start State -> each element in the list
# Goal State --> all combination sums up to the target
# Successor --> taken each valid combination that sums up to the target

# PATH --> valid combination of elements in the list sums up to the target
# CANDAIDATE --> list of elements 

#   DFS --> 2 
        # 1. when the sum = target --> add to result
        # 2. when the sum > target --> nothing (invalid)
        # 3. when the sum < target --> recursion with target - total_so_far
class Solution(object):
	def __init__(self):
		self.res = []

	def combinationSum(self, candidates, target):
		candidates.sort()
		self.dfs(candidates, target, 0, [])
		return self.res

	def dfs(self, candidates, target, start, path):
		if target == 0:
			self.res.append(path)
			return 
		if target < 0:
			return 
		else:
			for i in xrange(start, len(candidates)):
				self.dfs(candidates, target-candidates[i], i, path+[candidates[i]])
			return 

candidates = [2,3,6,7]
# candidates = [2,3,5]
# target = 8
target = 7
s = Solution()
print s.combinationSum(candidates, target)

# *********************************** Problem 4 ***********************************
# 59. Spiral Matrix 
# Given a positive integer n, generate a square matrix 
# filled with elements from 1 to n2 in spiral order.

# 1 --> construct a matrix n * n where initialize m[i][j] = - 1
# 2 --> interating throught from 1 to n*n
# 		call get_next_position(i, j, cur_direction) --> next position 
# class SpiralMatrix(object):
# 	def __init__(self, n):
# 		self.m = []
# 		self.n = n

# 	def matrixInitiliazaiton(self):
# 		for i in range(self.n):
# 			temp = [-1 for j in range(self.n)]
# 			self.m.append(temp)
# 		print self.m

# 	def nextPosition(self, i, j, cur_direction):
# 		# case 1 --> valid case, where we can keep going
# 		# case 2 --> invalid case, where we encounter corner 
# 		# LEFT
# 		# print cur_direction == "UP"
# 		if cur_direction == "LEFT":
# 			if i > 0 and self.m[i-1][j] == -1:
# 				print "LEFT: ", i, ' ', j, " ", cur_direction, " ", self.n
# 				return [i-1, j, "LEFT"]
# 			else:
# 				return self.nextPosition(i, j, "UP")
# 		# RIGHT
# 		if cur_direction == "RIGHT":
# 			if i < self.n - 1 and self.m[i+1][j] == -1:
# 				return [i+1, j, "RIGHT"]
# 			else:
# 				return self.nextPosition(i, j, "DOWN")
# 		# UP
# 		if cur_direction == "UP": 
# 			if j > 0 and self.m[i][j-1] == -1:
# 				return [i, j-1, "UP"]
# 			else:
# 				return self.nextPosition(i, j, "RIGHT")
# 		# DOWN
# 		if cur_direction == "DOWN":
# 			if j < self.n - 1 and self.m[i][j+1] == -1:
# 				return [i, j+1, "DOWN"]
# 			else:
# 				return self.nextPosition(i, j, "LEFT")

# 	def generateMatrix(self):
# 		self.matrixInitiliazaiton()
# 		# START STATE
# 		i = 0; j = 0
# 		start_position = [i, j]
# 		cur_direction = "RIGHT"
# 		self.m[i][j] = 1
# 		# OTHER STATES
# 		for k in range(1, self.n * self.n):
# 			nextPosition = self.nextPosition(i, j, cur_direction)
# 			print "MAIN: ", nextPosition
# 			i = nextPosition[0]; j = nextPosition[1]
# 			cur_direction = nextPosition[2]
# 			self.m[i][j] = k + 1
# 		print self.m

# m = SpiralMatrix(3)
# m.generateMatrix()


# *********************************** Problem 5 ***********************************
# 55. Jump Game
# Given an array of non-negative integers, you are initially positioned at the first index of the array.
# Each element in the array represents your maximum jump length at that position.
# Determine if you are able to reach the last index.
def canJump(nums):
    """
    :type nums: List[int]
    :rtype: bool
    """
    # convert nums into a list of intervals
    # where each interval is [start, end]
    # start = i, end = i + nums of steps
    intervals = [[i, i + nums[i]] for i in xrange(len(nums))]
    print intervals
    
    # Iterating through all the intervals 
    # while update max_interval each time
    # If max_interval don't overlap with current interval --> False
    # Otherwise update max_interval
    maxInterval = intervals[0]
    for i in xrange(1, len(intervals)):
        if maxInterval[1] >= intervals[i][0]:
            maxInterval[1] = max(intervals[i][1], maxInterval[1])
        else:
            return False 
    return True

ls1 = [2,3,1,1,4]
ls2 = [3,2,1,0,4]
print canJump(ls1)
print canJump(ls2)
   					


