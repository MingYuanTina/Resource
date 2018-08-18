class Solution:
    def transpose(self, A):
        res = []
        for i in range(0, len(A[0])):
            row = []
            for j in range(0, len(A)):
                row.append(A[j][i])
            res.append(row)
        return res

s = Solution()
print(s.transpose([[1,2,3], [4,5,6]]))
