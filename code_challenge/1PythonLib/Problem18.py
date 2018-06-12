# REFERENCE
	# 422. Valid Word Square
	# https://leetcode.com/problems/bold-words-in-string/description/

# DESCRIPTION
  # Given a sequence of words, check whether it forms a valid word square
  # Return true if it does, othersie return false
  # A sequence of workds forms a valid word square if the kth row and column
  # reads the same string, where 0 < k < max(numRows, numCols)

  # NOTE:
  # The number of words given is at least 1 and does not exceed 500.
  # Word length will be at least 1 and does not exceed 500.
  # Each word contains only lowercase English alphabet a-z.

# EXAMPLE
  # INPUT: ["abcd","bnrt","crmy","dtye"]
  # Output: true
  # EXPLANATION:
    # The first row and first column both read "abcd".
    # The second row and second column both read "bnrt".
    # The third row and third column both read "crmy".
    # The fourth row and fourth column both read "dtye".
    # Therefore, it is a valid word square.

# SOLUTION
class Solution:
  def validWordSquare(self, words):
    """
    :type words: List[str]
    :rtype: bool
    """
    s = []
    # Creating diagonal words
    for i in range(len(words)):
      temp = ""
      for j in range(len(words)):
        if i < len(words[j]):
          temp += words[j][i]
      s.append(temp)
    # Evaluate if each word matches
    for i in range(len(words)):
      if not words[i] == s[i]:
        return False
    return True

s = Solution()
words = ["abcd","bnrt","crmy","dtye"]
print(s.validWordSquare(words))

