# Problem 561
# =>  your task is to group these integers into n pairs of integer
# => say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) 
# => for all i from 1 to n as large as possible.

# => Example 1:
# => Input: [1,4,3,2]
# => Output: 4
# => Explanation: n is 2, and the maximum sum of 
# => pairs is 4 = min(1, 2) + min(3, 4)

def array_pair_sum(nums)
	count, total = 0, 0
	nums.sort.inject(0) do |sum, n|
		count % 2 == 0 ? sum += n : sum += 0
		count += 1
		total = sum
	end
	total
end
