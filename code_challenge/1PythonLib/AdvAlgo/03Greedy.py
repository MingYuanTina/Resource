from View import View
import collections

class Greedy(object):
    def monotoneIncreasingDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        # THE IDEA is to find first digit that has to be modified
        # and change rest of the digit to 9
        modified_i = 0
        str_N = str(N)
        str_l = list(str_N)
        int_l = map(lambda x: int(x), str_l)
        
        # RIGHT TO LEFT
        # iterate through N and find the first digit that N[i] < N[i-1]
        # change N[i] = 9 and N[i-1] -=1
        # iterate through rest of N 
        for i in range(len(int_l)-1, -1, -1):
            if i == 0:
                break
            if int_l[i] < int_l[i-1]:
                int_l[i] = 9
                int_l[i-1] -= 1
        
        # LEFT TO RIGHT
        # iterate througn N and find the digit that N[i+1] > N[i] change to 9 
        for i in range(0, len(int_l) - 1):
            if int_l[i] > int_l[i+1]:
                int_l[i+1] = 9
            
        str_l = map(lambda x: str(x), int_l)
        str_res = ''.join(str_l)
        res = int(str_res)
        return res

    def maxProfit(self, prices, fee):
        # PROBLEM DESCRIPTION
        # Your are given an array of integers prices,
    	# for which the i-th element is the price of a given stock on day i; 
    	# and a non-negative integer fee representing a transaction fee.
    	# You may complete as many transactions as you like, but you need to 
    	# pay the transaction fee for each transaction. 
    	# You may not buy more than 1 share of a stock at a time 
    	# (ie. you must sell the stock share before you buy again.)
    	# Return the maximum profit you can make.
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        total_profit = 0
        start_price = prices[0]
        for i in range(0, len(prices)):
            if start_price > prices[i]:
                start_price = prices[i]
            else:
                profit = prices[i] - start_price - fee
                if profit > 0:
                    start_price = prices[i] - fee
                    total_profit += profit
        return total_profit

    def findMinArrowShots(self, points):
        # PROBLEM NAME
        # 452. Minimum Number of Arrows to Burst Balloons
        
        # PROBLEM DESCRIPTION
        # Given a list of intervals, find the minimum number of overlapping intervals
        
        # PROBLEM TYPE
        """
        :type points: List[List[int]]
        :rtype: int
        """
        def findIntersect(p1, p2):
            x = max(p1[0], p2[0])
            y = min(p1[1], p2[1])
            if x > y:
                return []
            else:
                return [x, y]
        
        # BASE CASE
        if len(points) == 0:
            return 0
        # OTHER CASE
        points = [tuple(l) for l in points]
        points.sort(key=lambda x: x[0])
        res = 1
        pre_interval = points[0]
        for i in range(1, len(points)):
            temp_interval = findIntersect(points[i], pre_interval)
            if len(temp_interval) == 0:
                pre_interval = points[i]
                res += 1
            else:
                pre_interval = temp_interval
        return res

    def eraseOverlapIntervals(self, list_intervals):
        # PROBLEM NAME
        # 435. Non-overlapping Intervals

        # PROBLEM DESCRIPTION
        # Minimize the number of intervals to make rest of inputs non-overlapping

        # Problem TYPE
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        def ifIntersect(int1, int2):
            x = max(int1[0], int2[0])
            y = min(int1[1], int2[1])
            if x >= y:
                return False
            else:
                return True

        # Base Case
        if len(intervals) == 0:
            return 0
        
        # Other Case
        list_intervals.sort(key=lambda x: x[0])
        count = 0
        prev_interval = list_intervals[0]
        for i in range(1, len(list_intervals)):
            cur_interval = list_intervals[i]
            if ifIntersect(prev_interval, cur_interval):
                count += 1  
                if prev_interval[1] >= cur_interval[1]:
                    # remove prev_interval and set the cur_interval to be last interval
                    prev_interval = cur_interval
            else:
                prev_interval = cur_interval
        return count

    def leastInterval(self, tasks, n):
        # PROBLEM NAME
        # 621. Task Scheduler
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        freq = collections.Counter(tasks)
        freq = sorted(freq.values())
        max_val = freq[len(freq)-1] - 1
        idle_num = max_val * n
        freq.reverse()
        freq.pop(0)
        for f in freq:
            idle_num -= min(f, max_val)
        if idle_num > 0:
            return len(tasks) + idle_num
        else:
            return len(tasks)

    def partitionLabels(self, S):
        # PROBLEM NAME
        # 763. Partition Labels
        
        # Given a string, partition into substring as much as possible
        # with not each substring has common character
        # return each substring length as a list

        """
        :type S: str
        :rtype: List[int]
        """
        def mergeInterval(i1, i2):
            x1 = i1[0]
            x2 = i2[0]
            y1 = i1[1]
            y2 = i2[1]
            if x1 >= y2 or x2 >= y1:
                return None
            else:
                return [min(x1, x2), max(y1, y2)]
        
        # Step 1: Store each character start_index and end_index as tuple (index_list)
        # Step 2: Sort index_list by start_index 
        # Step 3: Scanning through index_list one by one 
        #       1. merge two tuples if they are overlap
        #       2. otherwise, keep them as seperate intervals
        
        # Step 1:
        start_list = list(S)
        reverse_list = start_list[:]
        reverse_list.reverse()
        dic = collections.Counter(start_list)
        index_list = []
        for key in dic.keys():
            start_index = start_list.index(key)
            end_index = len(start_list) - reverse_list.index(key) - 1
            index_list.append((start_index, end_index))
        
        # Step 2:
        index_list.sort(key=lambda x: x[0])
        
        # Step 3:
        res = [index_list[0]]
        for i in range(1, len(index_list)):
            i1 = res[len(res) - 1]
            i2 = index_list[i]
            temp = mergeInterval(i1, i2)
            if not temp:
                res.append(i2)
            else:
                res[len(res)-1] = temp
        
        # Step 4:
        res_diff = []
        for i in range(0, len(res)):
            res_diff.append(res[i][1] - res[i][0] + 1)
        return res_diff

obj = Greedy()

# MAX PROFIT
prices = [1, 3, 2, 8, 4, 9]
fee = 2
vw = View("A", "B", "C")
vw.run_view(obj.maxProfit, prices, fee)

print ""

# findMinArrowShots
user_input = [[10,16], [2,8], [1,6], [7,12]]
name = "452. Minimum Number of Arrows to Burst Balloons"
description = "Given a list of intervals, find the minimum number of overlapping intervals"
pro_type = "type points: List[List[int]], rtype: int"
vw = View(name, description, pro_type)
vw.run_view(obj.findMinArrowShots, user_input)

# eraseOverlapIntervals
intervals = [ [1,2], [2,3], [3,4], [1,3] ]
print ""
print "EraseOverlapIntervals: ", obj.eraseOverlapIntervals(intervals)

tasks = ["A","A","C","B","B","B"]
n = 2
print ""
print "leastInterval: ", obj.leastInterval(tasks, n)

# monotoneIncreasingDigits
N = 10
print ""
print "monotoneIncreasingDigits: ", obj.monotoneIncreasingDigits(N)


# Partition Labels
S = "ababcbacadefegdehijhklij"
print ""
print "partitionLabels", obj.partitionLabels(S)



