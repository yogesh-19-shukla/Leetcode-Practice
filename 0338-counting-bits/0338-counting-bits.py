class Solution(object):
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = []
        for i in range(n+1):
            sum = 0
            num = i
            while(num!=0):
                sum += num%2
                num = num/2
            res.append(sum)
        return res        

        