# REFERENCE
	# https://leetcode.com/problems/palindrome-permutation/description/

# QUESTION
	# Given a string, determine if a permutation of the string could form a palindrome.

# EXAMPLE
	# Example 1:	Input: "code"	Output: false
	# Example 2:	Input: "aab"	Output: true
	# Example 3:	Input: "carerac"	Output: true

# SOLUTION
class Solution:
  def canPermutePalindrome(self, s):
      """
      :type s: str
      :rtype: bool
      """
      # store the occurrence of each letter into dictionary
      l = list(s)
      d = {}
      for i in range(len(l)):
          if l[i] not in d.keys():
              d[l[i]] = 1
          else:
              d[l[i]] += 1
      
      # checking stage
      tolerance = 1
      for k in d:
          print(d[k] % 2)
          if d[k] % 2 != 0 and tolerance < 1:
              return False
          elif d[k] % 2 != 0 and tolerance == 1:
              tolerance -= 1
      return True
  
