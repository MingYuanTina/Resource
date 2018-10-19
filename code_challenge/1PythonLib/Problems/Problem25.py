# Oct 16th, 2017

# *********************************** Problem 1 ***********************
def maximumSwap(num):
    """
    :type num: int
    :rtype: int
    """
    # [2,7,3,6] --> [7,2,3,6] --> cur_min < cur_max and happens before swap 
    # [7,3,4,5] --> [7,5,4,3] --> cur_min = 3, cur_max = 4 swap them
    # [9,9,3,6] --> [9,9,6,3] --> cur_min = 3, cur_max = 6 swap them
    # [8,3,2,5] --> [8,3,2,5] --> cur_min = 2, cur_max = 
    # [9,9,7,3] --> no swap
    
    # Split num into a list of digit
    numL = [int(d) for d in str(num)]
    numSort = numL[:]
    numSort = sorted(numSort, reverse=True)
    
    # Compare the numSort and numL 
    # Whenever we see a mismatch --> there is pair such as numSort[i] > numL[i] and indexi > indexj
    for i in xrange(len(numL)):
        if numL[i] != numSort[i]:
            ## NEED to find out the last index appearing in the num list ##
            j = max(loc for loc, val in enumerate(numL) if val == numSort[i]) 
            numL[i], numL[j] = numL[j], numL[i]
            break
    
    # Convert list of num into a integer
    numL.reverse()
    res = 0
    for i in xrange(len(numL)-1, -1, -1):
        res = res + numL[i] * 10 ** i
    return res


    # ********************************** GREEDY APPROACH **********************************
    # At each digit of the input number in order, if there is a larger digit that occurs later, 
    # we know that the best swap must occur with the digit we are currently considering.
    
    # We will compute \text{last[d] = i}last[d] = i, the index \text{i}i of the 
    # last occurrence of digit \text{d}d (if it exists).
    # Afterwards, when scanning the number from left to right, if there is a larger digit in the future, 
    # we will swap it with the largest such digit; if there are multiple such digits, 
    # we will swap it with the one that occurs the lates

num1 = 2736
num2 = 8536
print "*********** MAX SWAP ************"
print maximumSwap(num1)
print maximumSwap(num2)