# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDepth(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        if root is None: return 0
        l = self.minDepth(root.left)
        r = self.minDepth(root.right)
        if root.left is None:
            return 1 + r
        if root.right is None:
            return 1 + l   
        return 1 + min(l,r)
        