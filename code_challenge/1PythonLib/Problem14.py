# REFERENCE
    # 256. Paint House
    # https://leetcode.com/problems/paint-house/description/

# DESCRIPTION
    # There are a row of n houses, each house can be painted with one of the three colors: red, blue or green.
    # The cost of painting each house with a certain color is different. You have to paint all the houses such that 
    # no two adjacent houses have the same color.
    # The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, 
    # costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, 
    # and so on... Find the minimum cost to paint all houses.

# EXAMPLE
    # Input: [[17,2,17],[16,16,5],[14,3,19]]
    # Output: 10
    # Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue. 
    #              Minimum cost: 2 + 5 + 3 = 10.

# SOLUTION (DP)
class Solution:         
    def minCost(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        if not costs:
            return 0
        r_m, g_m, b_m = costs[0]
        for i in range(1, len(costs)):
            r_m, g_m, b_m = min(g_m, b_m) + costs[i][0], min(r_m, b_m) + costs[i][1], min(r_m, g_m) + costs[i][2]
        return min(r_m, g_m, b_m)

# NOTE
    # 1. Characterize the structure of optimial solution by breaking into sub-problems
    # 2. Recursively define the value of optimal solution (base case + recusive case)
    # 3. Compute the value of optimal solution
    # 4. Write up the solution


# BAD SOLUTION (Greedy Algo won't work)
# This is a greedy algorith, but won't work in this case and return new minimum cos based on current state
# def getCosts(cost, color_c):
#     def setColor(cost, color_c, i, j):
#         if cost[i] < cost[j]:
#             color_c[0] += cost[i]
#             color_c[1] = i
#         else:
#             color_c[0] += cost[j]
#             color_c[1] = j
#         return color_c

#     if color_c[1] == 0:
#         return setColor(cost, color_c, 1, 2)
#     elif color_c[1] == 1:
#         return setColor(cost, color_c, 0, 2)
#     else:
#         return setColor(cost, color_c, 0, 1)
        
# class Solution:         
#     def minCost(self, costs):
#         """
#         :type costs: List[List[int]]
#         :rtype: int
#         """
#         # greedy algorithm
#         # start with red, green or blue
#         # count the minimum cost and compare each time
#         red_c = [0, 0]
#         green_c = [0, 1]
#         blue_c = [0, 2]
#         for i in range(len(costs)):
#             if i == 0:
#                 red_c[0] += costs[i][0]
#                 green_c[0] += costs[i][1]
#                 blue_c[0] += costs[i][2]
#             else:
#                 red_c = getCosts(costs[i], red_c)
#                 green_c = getCosts(costs[i], green_c)
#                 blue_c = getCosts(costs[i], blue_c)
#                 print(red_c)
#                 print(green_c)
#                 print(blue_c)
#         return min(red_c[0], green_c[0], blue_c[0])