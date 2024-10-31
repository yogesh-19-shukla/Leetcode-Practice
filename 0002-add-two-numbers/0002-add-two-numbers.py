# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        dummy = tail = ListNode(0)
        carry = 0
        while l1 or l2 or carry:
            d1 = d2 = 0
            if l1:
                d1 = l1.val
                l1 = l1.next
            if l2:
                d2 = l2.val
                l2 = l2.next
            sum = d1 + d2 + carry
            val = sum%10
            carry = sum //10
            newnode = ListNode(val)
            tail.next = newnode
            tail = tail.next
        return dummy.next    

        