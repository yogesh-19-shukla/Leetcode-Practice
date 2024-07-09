/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
     ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL;
        ListNode* prev = NULL;

        while(head != NULL){
           cur = head;
           head = head->next;
           cur->next = prev;
           prev = cur;
        }

        return prev;
    }    
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second!=NULL){
            if (first->val != second->val){
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};