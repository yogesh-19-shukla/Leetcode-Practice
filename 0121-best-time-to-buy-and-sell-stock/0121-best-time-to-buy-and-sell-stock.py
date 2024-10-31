class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        small = prices[0]
        profit = 0
        maxi = 0
        for i in range(len(prices)):
            if prices[i]<small:
                small = prices[i]
            profit = prices[i] - small
            maxi = max(maxi,profit)
        return maxi        
        