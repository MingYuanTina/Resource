# REFERENCE
	# 252. Meeting Rooms
	# https://leetcode.com/problems/shortest-word-distance/description/

# DESCRIPTION
	# Given an array of meeting time intervals consisting of start
  # and end times [[s1,e1],[s2,e2],...] (si < ei), 
  # determine if a person could attend all meetings.

# EXAMPLE
  # Input: [[0,30],[5,10],[15,20]]
  # Output: false
  
  # Input: [[7,10],[2,4]]
  # Output: true

# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

# SOLUTION
class Solution:
  def canAttendMeetings(self, intervals):
    """
    :type intervals: List[Interval]
    :rtype: bool
    """
    # Parsing intervals into dictionary for lookup
    d = {}
    for i in range(len(intervals)):
      temp = intervals[i].start
      if temp not in d.keys():
        d[intervals[i].start] = intervals[i].end
      else:
        return False
    print(d)
        
    start_l = sorted(d.keys())
    print(start_l)
    
    # Checking stage
    for i in range(len(intervals) - 1):
      # if end time for i overlaps with start time for i + 1
      # return false
      start_time = d[start_l[i]]
      print(start_time)
      end_time = start_l[i+1]
      print(end_time)
      if start_time > end_time:
        return False
    return True
            
