class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        slow = fast = slow2 = nums[0]
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow==fast:
                while slow!=slow2:
                   slow=nums[slow]
                   slow2=nums[slow2]
                return slow        
               
        
        
        