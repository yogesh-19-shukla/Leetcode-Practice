class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=NULL;
        
        while(head)
        {
            curr=head;
            head=head->next;
            curr->next=prev;
            prev=curr;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        
        //step 1 - using slow and fast pointer approach to find the mid of the list
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //step 2 - reverse the second half and split the List into two.
        ListNode* second=reverse(slow->next); // independent list second
        slow->next=NULL;
        ListNode* first=head; // independent list first
        
        //step 3 - merging the two list
        // second list can be shorter when LL size is odd
        while(second)
        {
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
};