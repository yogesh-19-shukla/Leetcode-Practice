class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i,j = 0 , len(height) -1;
        maxleft = height[i];
        maxright = height[j];
        res = 0;
        while i<j:
            if maxleft <= maxright:
                i+=1
                maxleft = max(maxleft,height[i])
                res += maxleft-height[i]
            else:
                j-=1
                maxright = max(maxright,height[j])
                res += maxright - height[j]
        return res;