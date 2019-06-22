# October 22th, 2018
# *********************************** Problem 1 ***********************************
def simplifyPath(path):
        # /../      ==> /
        # /home/    ==> /home
        # /./       ==> /
        # /a/.      ==> /a
        # /home//foo/   
        
        # Case 1: /a/b/c --> [a,b,c]    --> [a,b,c]
        # Case 2: ////  -->  [, , , ,]  --> []
        # Case 3: /../  -->  [..]       --> []
        # Case 4: /./   -->  [.]        --> []
        
        # Function take the path first split by slash
            # If elem (value of l[i]) is a character --> keep
            # If elem is . --> result_l.pop()
            # If ele, is .. --> result_l.pop() twice 
            # If elem is "" --> ignore   
        l = path.split('/')
        res = []
        #print l
        for elem in l:
            if not (elem == '.' or elem == ''):
                if res and elem == '..':
                    res.pop()
                    
                if elem != '..':
                    res.append(elem)
        #print res
        res_str = ""
        # Other Case
        for elem in res:
            res_str = res_str + "/" + elem
        
        # Base Case
        if res_str == "":
            res_str = "/"
    
        return res_str
                

print simplifyPath("/./")
print simplifyPath("/../")
print simplifyPath("/a/../")
print simplifyPath("/b/../")
print simplifyPath("/b//../")
print simplifyPath("/")
print simplifyPath("//a//////b/./../../../a/n/")
print simplifyPath("/a/b/c")

# *********************************** Problem 2 ***********************************
# 388. Longest Absolute File Path
	# dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext
		# [dir, \tsubdir, \tsubdir2, \t\tfile2]
		# Iterating through each element and count number of \t
			# we can know at which level the file is
			# current path ==> from level 0 to level n-1
					#level counter   	# res
		# dir ==> 	 	level:0		==>	[]
		# subdir ==> 	level:1		==> []
		# subdir2 ==> 	level:1		==> [\dir\subdir, ] 	==> cur_path = \dir\subdir1
		# file ==> 		level:2 	==> [\dir\subdir, ]		==> cur_path = \dir\subdir2\file
		# puath current path to res

# 6. BFS on input strings/string manipulation question
# 8. Implement payment system / Design an elevator / Design calculator
# 9. Simulation Oriented (e.g. write a recursive sudoku solver  )
# 10. Make a function that calculates relative path  

# *********************************** Problem 3 ***********************************
# 787. Cheapest Flights Within K Stops
	# Dijstra's algorithm
	# with checking if allow K stops each time

# *********************************** Problem 4 ***********************************
# 310. Minimum Height Trees
	# Create undirected graph
	# Take a list of all the nodes
	# Use BFS to find the maximum height of each tree
	# Find the minimum among all the maximum height with each possible root

# *********************************** Problem 5 ***********************************
# 547. Friend Circles
	# Merge List (Things in common)

# *********************************** Problem 6 ***********************************
# 638. Shopping Offers
	# 

