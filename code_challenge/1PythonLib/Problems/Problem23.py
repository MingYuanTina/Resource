# Oct 14th, 2018

# *********************************** Problem 1 ***********************************
# Jump Game ||
# [2,3,1,1,4]
# State State = 2 [0]
# Goal State = 4 [4]
# Successful Function
	# Takeing each node in the queue and generates all the valid state as far as 
	# we can reach and store max_distance and its total jumps
# [2,2,0,2,4,5]
			#   --> (1,2) --> jump = 1
	 		#   --> [2,0] --> (3-5) --> jump = 2
	 		#   --> (3,5) --> jump = 3
def jump(nums):
	total_jump = 0

	# base case
	if len(nums) < 2:
		return total_jump

	# queue --> (valid range that you can reach at each level)
	cur_range = [1, nums[0]+0]

	while (True):
		# increment the total jumps
		total_jump += 1

		# invalid case
		if cur_range[0] > cur_range[1]:
			return 0

		# check goal state (if we can reach out the last position already)
		if cur_range[1] >= len(nums) - 1:
			break;

		# pop from queue --> recalculate the range
		next_range = [cur_range[1] + 1]
		max_pos = 0
		for i in xrange(cur_range[0], next_range[0]):
			max_pos = max(max_pos, nums[i]+i)
		next_range.append(max_pos)	

		# update the next range
		cur_range = next_range

	return total_jump

print "*********** TOTAL JUMP ************"
print jump([2,2,0,2,4,5]), jump([2,3,1,1,4]), jump([])
print jump([1]), jump([0,1]), jump([1,0]), jump([1,2]), jump([2,1,0,3])

# *********************************** Problem 2 ***********************************
# 64. Minimum Path Sum
# Given a m x n grid filled with non-negative numbers, find a path from top left to 
# bottom right which minimizes the sum of all numbers along its path.

# Start Goal: (0,0)
# End Goal: (n-1,n-1)
# Function: take either left or right and add it to the path sum
	# return a list of sum 
	# At final step, we find out the minimum of the sum

class Path(object):
	def __init__(self, grid):
		self.grid = grid
		self.suml = []
		self.n = 0

	# Take current position and prev_sum
	# Add grid[i][j] to pre_sum
	# Recursively call right or down
	# When we reach the goal state --> (n-1, n-1) 
		# append cur_sum to suml
	def findAllSum(self, i, j, prev_sum):
		# Check invalid state
		if i >= self.n or j >= self.n:
			return

		# Calculation
		cur_sum  = prev_sum + self.grid[i][j]

		# Checking if goal state
		if i == self.n - 1 and j == self.n - 1:
			self.suml.append(cur_sum)
			return

		# ******** Recursion *********
		# call right
		self.findAllSum(i+1, j, cur_sum)
		# call down
		self.findAllSum(i, j+1, cur_sum)


	def minPathSum(self):
		# initialization set up
		self.n = len(self.grid)

		# base case
		if self.n == 0:
			return 0

		# other case
		self.findAllSum(0, 0, 0)
		min_sum = self.suml[0]
		for _sum in self.suml:
			min_sum = min(_sum, min_sum)
		return min_sum

	# DP SOLUTION
	def minPathSumDP(self):
		for i in xrange(1, len(self.grid[0])):
		    self.grid[0][i] = self.grid[0][i] + self.grid[0][i-1]
		for j in xrange(1, len(self.grid)):
		    self.grid[j][0] = self.grid[j][0] + self.grid[j-1][0]
		    
		for i in xrange(1, len(self.grid)):
		    for j in xrange(1, len(self.grid[0])):
		        self.grid[i][j] = min(self.grid[i-1][j], self.grid[i][j-1]) + self.grid[i][j]
		return self.grid[len(self.grid)-1][len(self.grid[0])-1]

grid = [[1,3,1],[1,5,1],[4,2,1]]
grid = [[1]]
grid = [[2,2], [4,4]] #  --> 2 + 2 + 4 = 10
p = Path(grid)
print "*********** PATH SUM ************"
print p.minPathSum()

# *********************************** Problem 3 ***********************************
# Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
# start with 1 in A --> 1[3] in B matched --> (2,4) does not match
# start with 2 in A --> 2[2] in B matched --> (3,1) does not match
# start with 3 in A --> 3[3] in B matched --> (2,2) match --> (1,1) match --> update max length
# O(n^2) # Iterating A, # matching each element in B  

# DP approach --> O(m+n)
# def findLength(A, B):

# A = [1,2,3,2,1]
# B = [3,2,1,4,7]
# print "*********** FIND LENGTH ************"
# print findLength(A, B)

# *********************************** Problem 4 ***********************************
# 120. Triangle
# Given a triangle, find the minimum path sum from top to bottom. 
# Each step you may move to adjacent numbers on the row below.
def minimumTotal(triangle):
    if not len(triangle):
        return 0
    
    # Other Case
    queue = [triangle[0][0]]
    
    for i in xrange(0, len(triangle)-1):
        # Initialize next queue
        nextl = triangle[i+1]
        
        # Itearating through all the children of each val from queue
        temp = [nextl[j] + queue[j] for j in xrange(len(queue))]
            
        nextl[0] = temp[0]
        for j in xrange(len(queue)):
            if j == len(queue) - 1:
                nextl[j+1] = nextl[j+1] + queue[j]
            else:
                nextl[j+1] = min(temp[j+1], nextl[j+1] + queue[j])
        
        # assign the next iteration
        queue = nextl
    
    _min = float('inf')
    return reduce((lambda x, y: min(x, y)), triangle[len(triangle)-1])

t1 = [[2],[3,4],[6,5,7],[4,1,8,3]]  # 2 + 3 + 5 + 1 = 11
t2 = [[-1],[3,2],[1,-2,-1]] 		# -1 + 2 + -2 = -1
t3 = [] # 0
t4 = [[1]]
print "*********** MININMUM TOTAL ************"
print minimumTotal(t1), minimumTotal(t2), minimumTotal(t3), minimumTotal(t4)


# *********************************** Problem 5 ***********************************
# Divide grid into 3 by 3 square one by on e
# Check if each square is valid

# Valid State --> 3x3 square is a perfect square 
# Invalid State --> 
	# grid row/col size >= 3
	# not a perfect square

def checkPerfectSquare(grid, br, bc):
	# Check Row
	temp = []
	for i in xrange(3):
		row = grid[br+i][bc:bc+3]
		row_sum = reduce((lambda x, y: x + y), row)
		temp.append(row_sum)
	# Check Col 
	for i in xrange(3):
		_sum = 0
		for j in xrange(3):
			_sum += grid[br+j][bc+i]
		temp.append(_sum)
	# print temp
	# Check Diagnal
	_sum = 0; _sum2 = 0;
	for i in xrange(3):
		_sum += grid[br+i][bc+i]
		_sum2 += grid[br+2-i][bc+2-i]
	temp.append(_sum)
	temp.append(_sum2)
	# Check Invalid
	print temp
	_set = set(temp)
	# print _set
	if len(_set) == 1:
		return True
	else:
		return False

def numMagicSquaresInside(grid):
	# Invalid Case
	if len(grid) < 3 or len(grid[0]) < 3:
		return 0
	elif len(grid) == 3 and len(grid[0]) == 3:
		return 0
	# Other Cases
	total = 0
	for i in xrange(0, len(grid)-3+1):
		for j in xrange(0, len(grid[0])-3+1):
			if checkPerfectSquare(grid, i, j):
				total += 1
	return total


g1 = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
g2 = [[10,3,5],[1,6,11],[7,9,2]]
print "*********** MAGIC SQUARE ************"
print numMagicSquaresInside(g1)
print numMagicSquaresInside(g2)

# *********************************** Problem 6 ***********************************
# 11 Container With Most Water    
#  optimize the area of rectange	
	# width * length
	# length -> length of arr --> max
	# width --> depend on each shorter of pair from list

# cur_max --> stores the max area calculated so far
# [1,8,6,2,5,4,8,3,7]
# cur_max --> (1,7) -->  (9-1) * min(1,7) = 9 * 1 = 9
# cur_max 
	# --> (8, 7) --> (8-1) * min(8, 7) = 8 * 7 = 56
# ...

# Start with (first, last) --> calculate the max
# Update cur_max
# Move forward the shorter line for next iteration
def maxArea(height):
	# Setup 
   	i = 0; j = len(height) - 1
 	max_area = 0

   	# Start with (first, last) --> calculate the max
	# Update cur_max
	# Move forward the shorter line for next iteration
   	while i < j:
   		cur_area = min(height[i], height[j]) * (j-i)
 		if cur_area > max_area:
 			max_area = cur_area
   		if height[i] < height[j]:
	   		i += 1
	   	else:
	   		j -= 1
	return max_area
h1 = [1,8,6,2,5,4,8,3,7]
h2 = [7,2,3,4,5,6]
h3 = [7,2,3,4,5,6]
print "*********** MAX AREA ************"
print maxArea(h1)
print maxArea(h2)
print maxArea(h3)

# *********************************** Problem 7 ***********************************
# 826. Most Profit Assigning Work
	# We have jobs: difficulty[i] is the difficulty of the ith job, 
	# and profit[i] is the profit of the ith job. 
	# Now we have some workers. worker[i] is the ability of the ith worker, 
	# which means that this worker can only complete a job with difficulty at most worker[i]. 
	# Every worker can be assigned at most one job, but one job can be completed multiple times.
	# For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  
	# If a worker cannot complete any job, his profit is $0.

# Max Prof
	# Most Diffculty
		# Maxsize most difficult job that each person can do

# worker = [4,5,6,7] sorted
	# worker 4 --> 4 --> 20
	# worker 5 --> 4 --> 20
	# worker 6 --> 6 --> 30
	# worker 7 --> 6 --> 30
	# worker 1 --> 0
	# worker 100 --> 10 --> 50

def maxProfitAssignment(difficulty, profit, worker):
	difficulty.sort()
	profit.sort()
	worker.sort()

	# Used for edge case
	profit = [0] + profit
	difficulty = [0] + difficulty
	#print "LEN: ", difficulty

	# For each worker find the highest reacheable work he/she can do
	tp = 0
	i = 0
	prev = 0
	for p in worker:
		while i < len(difficulty):
			# If a person can handle the tasks, keep searching
			if difficulty[i] < p:
				if i == len(difficulty) - 1:
					print "TEST MAX: ", profit[i], " ", p
					tp += profit[i]
					break
				prev = i
				#print "TEST LESS: ", profit[prev], " ", p, " ", i
				i += 1
			# Otherwise, reach limit
			elif difficulty[i] == p:
				#print "TEST EQUAL: ", profit[i], " ", p
				tp += profit[i]
				break
			elif difficulty[i] > p:
				#print "TEST GREATER: ", profit[prev], " ", p, " ", prev
				tp += profit[prev]
				break
	return tp

print "*********** MAX PROFIT ASSIGNMENT ************"
difficulty = [2,4,6,8,10]; profit = [10,20,30,40,50]; worker = [1,4,5,6,7,100]
# print maxProfitAssignment(difficulty, profit, worker)
print maxProfitAssignment(difficulty, profit, worker)


# *********************************** Problem 8 ***********************************
# 15. 3Sum
	# Given an array nums of n integers, are there elements a, b, c in nums 
	# such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
def getSum(nums, target):
	i = 0; j = len(nums) - 1
	#print nums, " ", target
	while i < j:
		if nums[i] + nums[j] > target:
			j -= 1
		elif nums[i] + nums[j] < target:
			i += 1
		else:
			return [nums[i], nums[j], -1 * target]
	return []

def threeSum(nums):
	nums.sort()
	n = len(nums)
	res = []
	#print "TEST: ", nums
	# Iterating through the list
	for i in xrange(n):
		print 'ITERATION: ', i
		# pop from the list
		elem = nums.pop(i)
		# check if there are any pair add to (-1) elem
		pair = getSum(nums, -1 * elem)
		# print 'INTERATION2: ', pair
		if pair:
			pair.sort()
			_tuple = (pair[0], pair[1], pair[2])
			res.append(_tuple)
		# add the number back to the list
		nums.insert(i, elem)
	final_res = list(set(res))
	return final_res
a1 = [-1, 0, 1, 2, -1, -4]
a2 = [-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
print "*********** THREE SUM ************"
print threeSum(a1)
print threeSum(a2)

# sort first
#	-1 --> if (i,i+k) = -(-1) --> add -1 back
#	0 --> if (i,i+k) = -(0) --> add 0 back



