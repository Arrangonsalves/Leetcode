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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head,*slow=head,*p=head;
        int flag=0;
        if(!head)
            return NULL;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                while(p!=slow)
                {
                    p=p->next;
                    slow=slow->next;
                }
                return slow;
                break;
            }
        }
        return NULL;
    }
};