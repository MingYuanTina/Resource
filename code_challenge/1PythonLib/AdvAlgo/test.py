
def search(nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        i = 0
        j = len(nums) - 1
        target_num = -1
        while i <= j and i >= 0 and j < len(nums):
            mid = int((i + j) / 2)
            print nums[mid], target
            if nums[mid] == target:
                target_num = mid
                break
            elif nums[mid] < target:
                i = mid + 1
                print "larger array", nums[mid]
            elif nums[mid] > target:
                j = mid - 1
                print "smaller array", nums[mid]
        return target_num

nums = [-1,0,3,5,9,12]
target = 9
print search(nums, target)