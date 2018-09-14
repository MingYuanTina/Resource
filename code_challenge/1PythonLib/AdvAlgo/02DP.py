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
obj2 = NumArray(nums)
print obj2.sumRange(0, 2) # 1
print obj2.sumRange(2, 5) # -1
print obj2.sumRange(0, 5) # -3





