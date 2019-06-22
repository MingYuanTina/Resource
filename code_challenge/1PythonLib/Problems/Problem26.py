# Oct 19th, 2017

# *********************************** Problem 1 ***********************************
# 890. Find and Replace Pattern
	# You have a list of words and a pattern, and 
	# you want to know which words in words matches the pattern.
	# A word matches the pattern if there exists a permutation of 
	# letters p so that after replacing every letter x 
	# in the pattern with p(x), we get the desired word.
	# Return a list of the words in words that match the given pattern. 
class StringMatch(object):
    # Processing pattern
    def standardStr(self, pattern):
        dic = {}
        l = [] # list of tuples where first element is c, second element is counter
        counter = -1
        for c in pattern:
            if c not in dic.keys():
                counter += 1
                dic[c] = counter
            l.append(dic[c])
        return l
    
    # Processing each word and compare with standard list
    def compareStr(self, word, l):
        dic = {}
        counter = -1
        for i, c in enumerate(word):
            if c not in dic.keys():
                counter += 1
                dic[c] = counter
            if dic[c] != l[i]:
                return False
        return True
                
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        
        # ["abc"], pattern "abb"
        
        # pre-set up of pattern a,b,b --> a list of integer --> if the two list of integer are being matched
            # counter increment whenever we see a different character that is not in the list
            # "a,b,b" --> {"a":0, "b":1, "b":1}
            # "a,b,c" --> {"a":0, "b":1, "c":2}
            # Iterating through the dictionary produced by given two string 
            # as long as two list are the same then it is matched with given pattern, otherwise false
            
        # m ==> len of the word list AND n ==> worst case of string given in the word list
        # Runtime --> O(m*n)
        standL = self.standardStr(pattern)
        length = len(standL)
        res = [] # final result list of words matched with pattern
        for w in words:
            if len(w) == length:
                if self.compareStr(w, standL):
                    res.append(w)
        return res
           
        # INITIAL SOLUTION

strMatch = StringMatch()
words = ["abc","deq","mee","aqq","dkd","ccc"]; pattern = "abb"
print strMatch.findAndReplacePattern(words, pattern)

# QUESTION TO DO LIST
# 1. 609. Find Duplicate File in System --> Dictionary
# 2. 647. Palindromic Substrings --> DP
# 3. 791. Custom Sort String
# 4. Evaluation of Prefix/Postifx Expression

# class PrefixEvaluation(object):
#     def __init__(self):

# SQUARE
# 6. BFS on input strings
# 7. String manipulation question
# 8. Implement payment system / Design an elevator / Design calculator
# 9. Simulation Oriented (e.g. write a recursive sudoku solver  )
# 10. Make a function that calculates relative path  

# BENCHLING
# 11. An algorithm problem involving manipulating DNA sequences.  
# 12. bio-related algorithm questions

# NAV TALENT
# RIDEBILL --> cool idea
