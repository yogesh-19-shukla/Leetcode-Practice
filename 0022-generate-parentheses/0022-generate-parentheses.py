class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        self.generate(n,0,0,"",res)
        return res
    def generate(self,n,open,close,str,res):
        if open==n and close==n:
            res.append(str)
        if open<n:
            self.generate(n,open+1,close,str+'(',res)
        if close<open:
            self.generate(n,open,close+1,str+')',res)
