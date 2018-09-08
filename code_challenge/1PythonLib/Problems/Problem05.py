# REFERENCE
	# 359. Logger Rate Limiter
	# https://leetcode.com/problems/logger-rate-limiter/description/

# DESCRIPTION
	# Design a logger system that receive stream of messages along with its timestamps, each message should be printed if and only if it is not printed in the last 10 seconds.
	# Given a message and a timestamp (in seconds granularity), return true if the message should be printed in the given timestamp, otherwise returns false.
	# is possible that several messages arrive roughly at the same time.

# EXAMPLE
	# Logger logger = new Logger();
	# // logging string "foo" at timestamp 1
	# logger.shouldPrintMessage(1, "foo"); returns true; 
	# // logging string "bar" at timestamp 2
	# logger.shouldPrintMessage(2,"bar"); returns true;
	# // logging string "foo" at timestamp 3
	# logger.shouldPrintMessage(3,"foo"); returns false;
	# // logging string "bar" at timestamp 8
	# logger.shouldPrintMessage(8,"bar"); returns false;
	# // logging string "foo" at timestamp 10
	# logger.shouldPrintMessage(10,"foo"); returns false;
	# // logging string "foo" at timestamp 11
	# logger.shouldPrintMessage(11,"foo"); returns true;

# SOLUTION
class Logger:
  def __init__(self):
    """
    Initialize your data structure here.
    """
    self.d = {}

  def shouldPrintMessage(self, timestamp, message):
    """
    Returns true if the message should be printed in the given timestamp, otherwise returns false.
    If this method returns false, the message will not be printed.
    The timestamp is in seconds granularity.
    :type timestamp: int
    :type message: str
    :rtype: bool
    """
    if message not in self.d.keys() or timestamp - self.d[message] >= 10:
      self.d[message] = timestamp
      print message
      return True
    else:
      return False

logger = Logger()
logger.shouldPrintMessage(1, "foo")
logger.shouldPrintMessage(2,"bar")
logger.shouldPrintMessage(3,"foo")
logger.shouldPrintMessage(8,"bar")
logger.shouldPrintMessage(10,"foo")
logger.shouldPrintMessage(11,"foo")

