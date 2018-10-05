import collections

# PROBLME GENERAL
class DP(object):
    def minCostClimbingStairs(self, cost):
        # ****************** PROBLEM DESCRIPTION ******************
        # On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

        # Once you pay the cost, you can either climb one or two steps. You need to find minimum cost 
        # to reach the top of the floor, and you can either start from the step with index 0, 
        # or the step with index 1.

        # ****************** EXAMPLE ****************** 
        # Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
        # Output: 6
        # Explanation: Cheapest is start on cost[0], 
        # and only step on 1s, skipping cost[3].
        
        # ****************** INPUT ******************
        """
        :type cost: List[int]
        :rtype: int
        """
        l = [0, 0] + cost + [0]
        total_cost = [0, 0]
        for i in range(2, len(l)):
            total_cost.append(min(total_cost[i-1] + l[i], total_cost[i-2] + l[i]))
        return total_cost[len(l)-1]

    def countBits(self, num):
        # ****************** PROBLEM DESCRIPTION ******************
        # Given a non negative integer number num. 
        # For every i in the range of 0 <= i <= number,
        # calculate the number of 1's in i and return as a list
            
        # ****************** INPUT ******************
        """
        :type num: int
        :rtype: List[int]
        """
        res = [0, 1, 1, 2]
        # base case
        if num < 3:
            return res[0:num+1]
        else:
            for i in range(4, num + 1):
                res.append(res[int(i / 4)] + res[i % 4])
        return res

    def coinChange(self, coins, amount):
        # PROBLEM DESCRIPTION
        # 322. Coin Change

        # PROBLEM DESCRIPTION
        # Given a list of denominators and desired amount
        # return minimum number of coints needed to make up the amount
        # otherwise, return -1
        # PROBLEM TYPE
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if amount == 0:
            return 0
        coins.sort()
        # list of nums where index i represent coin_val i
        # nums[i] represent the minimum coins needed to sum to i
        # nums[i] = -1 represents that the amount cannot be made up
        nums = [0]
        for i in range(1, amount + 1):
            min_val = 1000000
            for d in coins:
                if i - d < 0:
                    break
                else:
                    if nums[i-d] != -1:
                        sum_val = nums[i-d] + 1
                        if sum_val < min_val:
                            min_val = sum_val
            if min_val == 1000000:
                min_val = -1
            nums.append(min_val)
        return nums[amount]  

    def lengthOfLIS(self, nums):
        # PROBLEM DESCRIPTION
        # 322. Coin Change

        # PROBLEM DESCRIPTION
        # Given a list of non-negative integers,
        # return the max length of continous increasing subsequence

        # PROBLEM TYPE
        """
        :type nums: List[int]
        :rtype: int
        """
        # initialization
        l = [1] * len(nums)
        
        # list of largest continous length at index n
        for i in range(0, len(nums)):
            for j in range(0, i):
                if nums[i] > nums[j] and l[i] < l[j] + 1:
                    l[i] = l[j] + 1
            
        max_len = 0
        for temp in l:
            if temp > max_len:
                max_len = temp
        return max_len

    def deleteAndEarn(self, nums):
        # PROBLEM DESCRIPTION
        # 740. Delete and Earn

        # PROBLEM DESCRIPTION
        # Given an array nums of integers, you can perform operations on the array.
        # In each operation, you pick any nums[i] and delete it to earn nums[i] points. 
        # After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.
        
        # PROBLEM TYPE
        """
        :type nums: List[int]
        :rtype: int
        """
        # BASE CASE
        if not nums:
            return 0
        # OTHER CASE
        count_dic = collections.Counter(nums)
        dic = collections.defaultdict(lambda:0, count_dic)
        highest = max(nums)
        res = []
        i = 0
        for num in range(1, highest+1):
            if num == 1 or num == 2:
                res.append(num * dic[num])
            elif num == 3:
                res.append(res[i-2] + num * dic[num]) 
            else:
                res.append(max(res[i-2], res[i-3]) + num * dic[num])
            i += 1
            
        max_len = 0
        for i in range(0, len(res)):
            if max_len < res[i]:
                max_len = res[i]
        return max_len




# PROBLEM NAME -- 303. Range Sum Query - Immutable
class NumArray(object):
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        # build one dimensional array with n[i] as total sum
        total_sum = 0
        self.sum = [0]
        for num in nums:
            total_sum += num
            self.sum.append(total_sum)
        print self.sum
        

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sum[j+1] - self.sum[i]


obj1 = DP()
print "COUNT BITS"
print obj1.countBits(3)   # Base Case
print obj1.countBits(10)

print ""
print "COIN CHANGE"
coins = [1,2,5]
amount = 11
print obj1.coinChange(coins, amount)

print ""
print "RANGE SUM QUERY"
nums = [-2, 0, 3, -5, 2, -1]
print "INPUT: ", nums
obj2 = NumArray(nums)
print obj2.sumRange(0, 2) # 1
print obj2.sumRange(2, 5) # -1
print obj2.sumRange(0, 5) # -3

print ""
print "LENGTH OF LONGEST CONTINUOUS SUBSEQUENCE"
nums = [10,9,2,5,3,7,101,18]
print "INPUT: ", nums
print "OUTPUT: ", obj1.lengthOfLIS(nums)

print ""
print "Delete and EARN"
nums = [8,10,4,9,1,3,5,9,4,10]
print "INPUT: ", nums
print "OUTPUT: ", obj1.deleteAndEarn(nums)

