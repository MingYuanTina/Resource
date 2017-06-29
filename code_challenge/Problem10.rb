# Problem 475
# => find complement number
# input: 5 --> 101
# output: 2 --> 010

def convert_binary(num)
	binary = Array.new()
	while num != 1
		binary.insert(0, num % 2)
		num = num / 2
	end
	binary.insert(0, 1)
	binary
end

def convert_num(binary)
	binary = binary.reverse!
	count, total = 0, 0
	for num in binary 
		num = num == 1 ? 0 : 1
		total = (2 ** count) * num + total
		count += 1
	end
	total
end

def find_complement(num)
	binary = convert_binary(num)
	binary = convert_num(binary)
end