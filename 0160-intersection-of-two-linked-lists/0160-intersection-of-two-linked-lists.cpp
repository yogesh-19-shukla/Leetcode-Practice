/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int a = 0, b = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        if (headA == NULL || headB == NULL)
            return NULL;
        while (tempA != NULL) {
            a++;
            tempA = tempA->next;
        }
        while (tempB != NULL) {
            b++;
            tempB = tempB->next;
        }
        int diff = abs(a - b);
        if (a > b) {
            while (diff) {
                headA = headA->next;
                diff--;
            }
        } else {
            while (diff) {
                headB = headB->next;
                diff--;
            }
        }

        while (headA != NULL) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};