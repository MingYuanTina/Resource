# Self Dividing Numbers
class Solution:
    def getList(self, num):
        l = []
        while True:
            if int(num / 10) == 0:
                l.append(num)
                break
            l.append(num % 10)
            num = int(num / 10)
        return l
    
    def selfDividingNumber(self, num, l):
        for i in range(0, len(l)):
            if not l[i] or num % l[i] != 0:
                return False
        return True
    
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        res = []
        for i in range(left, right + 1):
            l = self.getList(i)
            if self.selfDividingNumber(i, l):
                res.append(i)
        print(res)
        return res

s = Solution()
s.selfDividingNumbers(1,22)