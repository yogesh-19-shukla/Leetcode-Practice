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
    ListNode* reverselist(ListNode* head)
    {
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
private:
    ListNode* getKth(ListNode* temp, int k)
    {
        k--;
        while(temp!=NULL && k>0){
            temp = temp->next;
            k--;
        }
        return temp;
    }        
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL;
        while(temp!=NULL){
            ListNode* kthnode = getKth(temp,k);
            if(kthnode == NULL){
                if(prevlast){
                    prevlast->next = temp;                  
                }
                break;
            }
        
        ListNode* nextNode = kthnode->next;
        kthnode->next = NULL;
        reverselist(temp);
        //for 1st group 
        if(temp == head){
            head = kthnode;
        }else{
            prevlast -> next = kthnode; 
        }
        prevlast = temp;
        temp = nextNode;
        }
        return head;
    }
};