class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l,h = 0 , len(nums)-1
        while l<=h:
            mid = l + (h-l)/2
            if nums[mid]==target:
                return mid
            if nums[l]<=nums[mid]:
                if (nums[l]<=target and target<=nums[mid]):
                    h = mid - 1
                else:
                    l = mid + 1
            else:
                if nums[mid]<=target and target<=nums[h]:
                    l = mid + 1
                else:
                    h = mid - 1
        return -1            

                    
        