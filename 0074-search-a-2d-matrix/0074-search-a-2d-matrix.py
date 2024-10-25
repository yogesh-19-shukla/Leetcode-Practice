class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        n,m = len(matrix), len(matrix[0])
        row,col = 0,m-1
        while row<n and col>=0:
            cur = matrix[row][col]
            print cur
            if cur==target:  return True
            elif(cur<target): 
                row +=1
            else:
                col -=1
        return False            

        
        