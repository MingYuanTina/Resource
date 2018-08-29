import sys
import operator

# HELPER FUNCTION
def process_matrix(matrix, row, col):
	d = {}

	for i in range(0, row):
		for j in range(0, col):
			temp = matrix[i][j]
			if temp not in d.keys():
				d[temp] = 1
			else:
				d[temp] += 1
	return d

def process_dic(dic):
	pair_list = dic.items()
	pair_list = sorted(pair_list, key=operator.itemgetter(0))
	pair_list = sorted(pair_list, key=operator.itemgetter(1), reverse=True)
	return pair_list

def print_result(res):
	print len(res)
	for i in range(0, len(res)):
		print res[i][1], res[i][0]

# read input
def main():
	num_set = int(raw_input())
	for i in range(0, num_set):
		row_col = raw_input().split(" ")
		row = int(row_col[0])
		col = int(row_col[1])

		# read in matrix
		m = []
		for i in range(0, row):
			m.append(list(raw_input()))

		# process matrix
		dic =	process_matrix(m, row, col)
		result = process_dic(dic)

		# print the result
		print_result(result)

main()	