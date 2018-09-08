# REFERENCE
	# 293. Flip Game
	# https://leetcode.com/problems/flip-game/description/

# DESCRIPTION
	# You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -,
  # you and your friend take turns to flip two consecutive "++" into "--". 
  # The game ends when a person can no longer make a move and therefore the other person will be the winner.
  # Write a function to compute all possible states of the string after one valid move.

# EXAMPLE
  # Input: s = "++++"
  # Output: 
  # [
  #   "--++",
  #   "+--+",
  #   "++--"
  # ]

# SOLUTION
class Solution:
    def generatePossibleNextMoves(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        l = list(s)
        res = []
        
        # Other Cases
        for i in range(0, len(l)-1):
            temp = ""
            if l[i] == l[i+1] and l[i] == "+":
                if l[i] == "+":
                    temp = s[:i] + "--" + s[i+2:]
                res.append(temp)
        return res

s = Solution()
print(s.generatePossibleNextMoves("++++"))
