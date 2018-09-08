# REFERENCE
	# 758. Bold Words in String
	# https://leetcode.com/problems/bold-words-in-string/description/

# DESCRIPTION
	# Given a set of keywords words and a string S, 
	# make all appearances of all keywords in S bold. 
	# Any letters between <b> and </b> tags become bold.
	# The returned string should use the least number of tags possible, 
	# and of course the tags should form a valid combination.
	

# EXAMPLE
	# INPUT: words = ["ab", "bc"] and S = "aabcd", 
	# OUTPUT: "a<b>abc</b>d"

	# INPUT: words = ["b","dee","a","ee","c"] and S = "cebcecceab"
	# OUTPUT: "<b>c</b>e<b>bc</b>e<b>cc</b>e<b>ab</b>"

# SOLUTION
class Solution:
  def boldWords(self, words, S):
    """
    :type words: List[str]
    :type S: str
    :rtype: str
    """
    l = list(S)
    res = [] # list of pairs where first element is the char and second element is the 0/1 to represent bold 
    for i in range(len(l)):
      res.append([l[i], 0])
    
    # If there is matched string
    # marked the res as bold for second element
    for i in range(len(words)):
      curr = words[i]
      for j in range(len(S) - len(curr)+1):
        sub_str = S[j:j+len(curr)]
        if curr == sub_str:
          for z in range(j, j+len(curr)):
            res[z][1] = 1
    
    c = 0
    for i in range(len(res)-1):
      # detecting beginnning bold by searching for ["",0], ["",1] pattern         
      if i == 0 and res[i][1]:            # base case for beginning
        S = "<b>" + S
        c += 3
      elif not res[i][1] and res[i+1][1]:
        S = S[:c+1] + "<b>" + S[c+1:]
        c += 3
      
      # detecting ending bold by searching for ["",1], ["",0] pattern 
      if res[i+1][1] and i+2 == len(res): # base case for ending 
        S = S[:c+2] + "</b>" + S[c+2:]
      elif (res[i][1] and not res[i+1][1]):
        S = S[:c+1] + "</b>" + S[c+1:]
        c += 4
      c += 1
        
    return S

s = Solution()
words = ["ab", "bc"] 
S = "aabcd"
print(s.boldWords(words, S))
words1 =["b","dee","a","ee","c"] 
S1 = "cebcecceab"
print(s.boldWords(words1, S1))

