# REFERENCE
	# 346. Moving Average from Data Stream
	# https://leetcode.com/problems/moving-average-from-data-stream/description/

# DESCRIPTION
	# Given a stream of integers and a window size, 
	# calculate the moving average of all integers in the sliding window.


# EXAMPLE
	# MovingAverage m = new MovingAverage(3);
	# m.next(1) = 1
	# m.next(10) = (1 + 10) / 2
	# m.next(3) = (1 + 10 + 3) / 3
	# m.next(5) = (10 + 3 + 5) / 3


# SOLUTION
class MovingAverage:

  def __init__(self, size):
    """
    Initialize your data structure here.
    :type size: int
    """
    self.size = size
    self.d = []
    

  def next(self, val):
    """
    :type val: int
    :rtype: float
    """
    self.d.append(val)  # append the value into the list
    sum = 0
    if len(self.d) < self.size:
      for i in range(len(self.d)):
        sum += self.d[i]
      return float(sum/len(self.d))
    else:
      for i in range(self.size):
        sum += self.d[len(self.d)-i-1]
      return float(sum/self.size)

m = MovingAverage(3)
print(m.next(1))
print(m.next(10))
print(m.next(3))
print(m.next(5))
