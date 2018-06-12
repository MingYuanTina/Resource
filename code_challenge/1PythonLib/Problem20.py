# REFERENCE
	# 624. Maximum Distance in Arrays
	# https://leetcode.com/problems/maximum-distance-in-arrays/description/

# DESCRIPTION
	# Given m arrays, and each array is sorted in ascending order. Now you can 
	# pick up two integers from two different arrays (each array picks one) and 
	# calculate the distance. We define the distance between two integers a and b 
	# to be their absolute difference |a-b|. Your task is to find the maximum distance.
	# Note:
		# Each given array will have at least 1 number. There will be at least two non-empty arrays.
		# The total number of the integers in all the m arrays will be in the range of [2, 10000].
		# The integers in the m arrays will be in the range of [-10000, 10000].

# EXAMPLE
	# INPUT 
	# [[1,2,3],
	#  [4,5],
	#  [1,2,3]]
	# OUTPUT: 4

# SOLUTION
class Solution:
  def maxDistance(self, arrays):
    """
    :type arrays: List[List[int]]
    :rtype: int
    """
    # brute force (n^2)*(n^2)
    # improved version 1 (as since we know that each list if sorted) -- > n^2
    # max_d = 0
    # for i in range(len(arrays)):
    #     for j in range(len(arrays)):
    #         if i != j:]
    #             dis = abs(arrays[i][0] - arrays[j][len(arrays[j])-1])
    #             if dis > max_d:
    #                 max_d = dis
    # return max_d
    
    # improved version 2 (based on version 1 and stored min and max)
    min_v = arrays[0][0]
    max_v = arrays[0][len(arrays[0])-1]
    max_d = 0
    for i in range(1, len(arrays)):
      dis_1 = arrays[i][len(arrays[i])-1] - min_v
      dis_2 = max_v - arrays[i][0]
      max_d = max(max_d, dis_1, dis_2)
      min_v = min(min_v, arrays[i][0])
      max_v = max(max_v, arrays[i][len(arrays[i])-1])   
    return max_d

s = Solution()
arrays = [[1,2,3],[4,5],[1,2,3]]
print(s.maxDistance(arrays))
