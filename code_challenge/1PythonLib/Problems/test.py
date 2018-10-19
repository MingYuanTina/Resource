#  optimize the area of rectange	
	# width * length
	# length -> length of arr --> max
	# width --> depend on each shorter of pair from list

# cur_max --> stores the max area calculated so far
# [1,8,6,2,5,4,8,3,7]
# cur_max --> (1,7) -->  (9-1) * min(1,7) = 9 * 1 = 9
# cur_max 
	# --> (8, 7) --> (8-1) * min(8, 7) = 8 * 7 = 56
# ...


# Start with (first, last) --> calculate the max
# Update cur_max
# Move forward the shorter line for next iteration
def maxArea(height):
	# Setup 
   	i = 0; j = len(height) - 1
 	max_area = 0

   	# Start with (first, last) --> calculate the max
	# Update cur_max
	# Move forward the shorter line for next iteration
   	while i < j:
   		cur_area = min(height[i], height[j]) * (j-i-1)
 		if cur_area > max_area:
 			max_area = cur_area
   		if height[i] < height[j]:
	   		i += 1
	   	else:
	   		j -= 1
	return max_area
h1 = [1,8,6,2,5,4,8,3,7]
print maxArea(height)

