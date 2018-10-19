import sys

def valid_string(matrix, _str):
	print matrix, " ", _str
	return True


matrix = [['A', 'B', 'C', 'C'], ['D', 'E', 'C', 'B'], ['B', 'A', 'E', 'F'], ['B', 'A', 'B', 'A']]
_str = "ABCCEBA"


res = valid_string(matrix, _str)
print res