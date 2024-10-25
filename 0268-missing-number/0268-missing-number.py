class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a,b = 0,0
        for i in range(len(nums)+1):
            a = a ^ i
        for j in range(len(nums)):
            b = b ^ nums[j]
        return a ^ b        

        