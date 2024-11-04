class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        i,res,maxcount = 0,0,0
        count = {}
        for r in range(len(s)):
            count[s[r]] = 1 +  count.get(s[r],0)
            maxcount = max(maxcount,count[s[r]])
            while(r-i+1-maxcount>k):
                count[s[i]] -=1
                i +=1
            res = max(res,r-i+1)
            r +=1
        return res            
        