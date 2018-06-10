# REFERENCE
	# 243. Shortest Word Distance
	# https://leetcode.com/problems/shortest-word-distance/description/

# DESCRIPTION
	# Given a list of words and two words word1 and word2, 
	# return the shortest distance between these two words in the list.

# EXAMPLE
	# Assume that words = ["practice", "makes", "perfect", "coding", "makes"]
	# Input: word1 = "makes", word2 = "coding"
	# Output: 1

# SOLUTION
class Solution:
  def shortestDistance(self, words, word1, word2):
    """
    :type words: List[str]
    :type word1: str
    :type word2: str
    :rtype: int
    """
    # 1. find all the occurrence index for word1 and word2 as l1 and l2
    # 2. find the minimum adjacent distance of l1 and l2 as l 
    
    l1 = []
    l2 = []
    l = []
    
    # Step 1
    for i in range(len(words)):
      if words[i] == word1:
        l1.append(i)
      if words[i] == word2: 
        l2.append(i)
  
    # Step 2
    m = len(words) # maximum could be
    i = 0
    j = 0
    while i < len(l1) and j < len(l2):
      # record the temporary smallest
      temp = abs(l1[i] - l2[j])
      if temp < m:
        m = temp
      
      if l1[i] <= l2[j]:
        i += 1
      else:
        j += 1
    return m

words = ["practice", "makes", "perfect", "coding", "makes"]
word1 = "coding"
word2 = "practice"
s = Solution()
print(s.shortestDistance(words, word1, word2))
