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
        print(res)
        return res


objs = DP()
print "COUNT BITS"
objs.countBits(3)   # Base Case
objs.countBits(10)



