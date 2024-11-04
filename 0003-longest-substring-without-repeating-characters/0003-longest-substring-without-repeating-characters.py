class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        i,res = 0,0
        charSet = set()

        for r in range(len(s)):
            while s[r] in charSet:
                charSet.remove(s[i])
                i +=1
            charSet.add(s[r])
            res = max(res, r-i+1)
        return res         
        
        