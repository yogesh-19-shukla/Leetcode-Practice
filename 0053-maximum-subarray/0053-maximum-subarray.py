class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum = 0
        maxi = nums[0]
        for i in range(0,len(nums)):
            sum += nums[i]
            if sum>maxi: maxi = sum
            if sum<0: sum = 0
            
        return maxi    
        