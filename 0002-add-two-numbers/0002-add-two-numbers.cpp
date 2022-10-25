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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=NULL,*q=l3;
        int c=0,d;
        if(l1==NULL && l2==NULL)
            return NULL;
        if(l1!=NULL && l2==NULL)
            return l1;
        if(l1==NULL && l2!=NULL)
            return l2;
        
        while(l1 && l2)
        {
            ListNode *p=new ListNode;
            if(l3==NULL)
                l3=p;
            else
                q->next=p;
            q=p;
            d=l1->val+l2->val+c;
            c=d/10;
            d=d%10;
            //ut<<"c:"<<c<<" "<<"d:"<<d<<endl;
            p->val=d;
            l1=l1->next;
            l2=l2->next;   
        }
        while(l1)
        {
            ListNode *p=new ListNode;
            q->next=p;
            q=p;
            d=l1->val+c;
            c=d/10;
            d=d%10;
            p->val=d;
            l1=l1->next;
        }
        while(l2)
        {
            ListNode *p=new ListNode;
            q->next=p;
            q=p;
            d=l2->val+c;
            c=d/10;
            d=d%10;
            p->val=d;
            l2=l2->next;
        }
        if(c!=0)
        {
            ListNode *p=new ListNode;
            q->next=p;
            p->val=c;
        }
        return l3;
    }
};