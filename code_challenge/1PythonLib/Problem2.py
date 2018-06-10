# REFERENCE
	# https://leetcode.com/problems/find-anagram-mappings/description/

# QUESTION
	# 760. Find Anagram Mappings
	# Given two lists Aand B, and B is an anagram of A. 
	# B is an anagram of A means B is made 
	# by randomizing the order of the elements in A.

# EXAMPLE
	# Example 1:	
	#		Input: A = [12, 28, 46, 32, 50], B = [50, 12, 32, 46, 28]
	#		Output: [1, 4, 3, 2, 0]

# SOLUTION
class Solution:
    def anagramMappings(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        d = {}
        for i in range(len(B)):
            d[B[i]] = i
        l = []
        for i in range(len(A)):
            l.append(d[A[i]])
        return l