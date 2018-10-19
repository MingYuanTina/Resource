# *********************************** Problem 1 ***********************************
# 31. Next Permutation
	# Implement next permutation, which rearranges numbers into 
	# the lexicographically next greater permutation of numbers.
	# If such arrangement is not possible, it must rearrange it as the 
	# lowest possible order (ie, sorted in ascending order).
	# The replacement must be in-place and use only constant extra memory.



# *********************************** Problem 2 ***********************
# 56. Merge Intervals
def merge(intervals):
    """
    :type intervals: List[Interval]
    :rtype: List[Interval]
    """
    # Initialize intervals as list of tuples
    tuple_list = []
    for interval in intervals:
        tuple_list.append((interval[0], interval[1]))
    tuple_list = sorted(tuple_list, key=lambda x: x[0])
    
    # If int1 and int2 can be merged, return merged
    # Otherwise return two intervals seperately
    def getIntervalOverlapped(int1, int2):
        x1 = int1[0]; y1 = int1[1]
        x2 = int2[0]; y2 = int2[1]
        #print "TEST1: ", int1, " ", int2
        if (y1 >= x2 and y1 <= y2) or (y2 >= x1 and y2 <= y1):
            return [(min(x1, x2), max(y1, y2))]
        else:
            return [int2, int1]
    
    # Interating all intervals
    # Pop from result list and check if the current interval can be appended
    # Base Case: 0 or 1 intervals --> nothing to merge --> return immediately
    if len(intervals) <= 1:
        return intervals
    # Other Cases: keep appending intervals to the last interval of result if we can
    res = [tuple_list[0]] # result list
    for i in xrange(len(tuple_list)):
        res_interval = res.pop()
        temp = getIntervalOverlapped(tuple_list[i], res_interval)
        res += temp
    res = sorted(res, key=lambda x: x[0])
    return res

int1 = [[2,3],[2,2],[3,3],[1,3],[5,7],[2,2],[4,6]]
int2 = [[1,3],[2,6],[8,10],[15,18]]
int3 = [[1,4],[4,5]]
print merge(int1)
print merge(int2)
print merge(int3)



