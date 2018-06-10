# REFERENCE
	# https://leetcode.com/problems/shortest-distance-in-a-line/description/

# QUESTION
	# Table point holds the x coordinate of some points on x-axis in a plane, which are all integers.
	# Write a query to find the shortest distance between two points in these points.
	# | x   |
	# |-----|
	# | -1  |
	# | 0   |
	# | 2   |
	# The shortest distance is '1' obviously, which is from point '-1' to '0'. So the output is as below:
	# | shortest|
	# |---------|
	# | 1       |

# SOLUTION
# using select statement without join
select min(abs(p1.x - p2.x)) as shortest 
from point as p1, point as p2 
where p1.x <> p2.x

# using join solution
select abs(p1.x - p2.x) as shortest
from point p1 
join point p2 
on p1.x <> p2.x
order by shortest
limit 1