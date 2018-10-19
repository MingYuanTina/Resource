import sys


# 79. Word Search
# Given79. Word Search a 2D board and a word, find if the word exists in the grid.
# The word can be constructed from letters of sequentially adjacent cell, 
# where "adjacent" cells are those horizontally or vertically neighboring. 
# The same letter cell may not be used more than once.

# board =[
#   ['A','B','C','E'],
#   ['S','F','C','S'],
#   ['A','B','C','D']
# ]
# Given word = "ABCCED", return true.
# Given word = "SEE", return true.
# Given word = "ABCB", return false.
# Given word = "BCD", return false

class WordSearch(object):
	def __init__(self, board, ls):
		self.board = board
		self.ls = ls
		self.row = len(self.board)
		self.col = len(self.board[0])

	# (i, j) is the position of the board
	# cp is the current position of the word list
	# word search  recusively checks if current word matches 
	# with word on board with given position

	# 1. cp is end of list --> everything matched --> true
	# 2. i, j not valid index --> false
	# 3. board(i, j) != self.ls[cp] --> false, else --> true
	def word_search(self, board, i, j, cp):
		if cp == len(self.ls) - 1:
			return True 
		if not (i >= 0 and i < self.row) or not (j >= 0 and j < self.col):
			return False 
		if board[i][j] == self.ls[cp]:
			board[i][j] = "0"
			# Keep tracking all four directionary
			up = self.word_search(board, i+1, j, cp+1)
			down = self.word_search(board, i-1, j, cp+1)
			left = self.word_search(board, i, j-1, cp+1)
			right = self.word_search(board, i, j+1, cp+1)
			board[i][j] = self.ls[cp]
			if up or down or left or right:
				return True 
			else:
				return False
		else:
			return False 


# board = [["a","a","a","a"],["a","a","a","a"],["a","a","a","a"]]
# word  = "aaaaaaaaaaaaa"

board =[['A','B','C','E'],['S','F','C','S'],['A','B','E','D']]
word = "ABCCED"

ls = list(word)
s = WordSearch(board, ls)
print s.word_search(board, 0, 0, 0)



