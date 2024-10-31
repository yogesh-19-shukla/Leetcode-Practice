# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """
        slow = fast = head
        if head.next is None: return head.next
        while n>0:
            fast = fast.next
            n -=1
        if fast is None:
            return head.next    
        while fast.next:
            slow = slow.next
            fast = fast.next
        slow.next = slow.next.next
        return head    


        