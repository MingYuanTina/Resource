# REFERENCE
    # 246. Strobogrammatic Number
    # https://leetcode.com/problems/strobogrammatic-number/description/

# DESCRIPTION
    # A strobogrammatic number is a number that looks the same 
    # when rotated 180 degrees (looked at upside down).
    # Write a function to determine if a number is strobogrammatic. 
    # The number is represented as a string.

# EXAMPLE
    # Input:  "69"
    # Output: true

    # Input:  "88"
    # Output: true
    
    # Input:  "962"
    # Output: false

# SOLUTION
class Solution:
    def isStrobogrammatic(self, num):
        """
        :type num: str
        :rtype: bool
        """
        d = {'0': 0, '1': 0, '6': 0, '8': 0, '9': 0}
        l = list(num)
        r = []
        for i in range(len(num)):
            if not l[i] in d.keys():
                return False
            else:
                if l[i] == "6":
                    r.append("9")
                elif l[i] == "9":
                    r.append("6")
                else:
                    r.append(l[i])
        r.reverse()
        r_str = "".join(r)
        if num == r_str:
            return True
        else:
            return False

s = Solution()
print(s.isStrobogrammatic("69"))    # True
print(s.isStrobogrammatic("101"))   # True
print(s.isStrobogrammatic("88"))    # True
print(s.isStrobogrammatic("6886"))  # False
print(s.isStrobogrammatic("1234"))  # False



