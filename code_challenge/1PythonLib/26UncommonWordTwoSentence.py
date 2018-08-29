# ************************ QUESTION ************************
# We are given two sentences A and B.  (A sentence is a string of space separated words.  
#   Each word consists only of lowercase letters.)
#   A word is uncommon if it appears exactly once in one of the sentences, 
#   and does not appear in the other sentence.
#   Return a list of all uncommon words. 

# ************************ IMPLEMENTATION ************************ 
class Solution(object):
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        # TIME COMPLEXITY: O(n^2)
        # SPACE COMPLEXITY
        s = A + " " + B
        l = s.split()
        # res = []
        # for i in range(0, len(l)):
        #     if l.count(l[i]) == 1:
        #         res.append(l[i])
        # return res
    
        # TIME COMPLEXITY: O(n)
        # SPACE COMPLEXITY: O(n)
        dic = {}
        res = []
        for i in range(0, len(l)):
            if l[i] not in dic.keys():
                dic[l[i]] = 1
            else:
                dic[l[i]] += 1
        for k, v in dic.items():
            if v == 1:
                res.append(k)
        return res

# ************************ TEST CASE ************************
s = Solution()
A = "this apple is sweet"
B = "this apple is sour"
print(s.uncommonFromSentences(A, B))

A = "apple apple"
B = "banana"
print(s.uncommonFromSentences(A, B))
