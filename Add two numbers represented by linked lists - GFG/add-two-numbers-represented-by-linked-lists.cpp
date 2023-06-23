//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node*head)
    {
        if(head==NULL ||head->next==NULL)
            return head;
        Node *curr=head,*nxt=curr->next,*prev=NULL;
        while(nxt)
        {
            curr->next=prev;
            prev=curr;
            curr=nxt;
            nxt=nxt->next;
        }
        curr->next=prev;
        return curr;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        if(first==NULL && second==NULL)
            return NULL;
        else if(first==NULL && second!=NULL)
            return second;
        else if(first!=NULL && second==NULL)
            return first;
        
        Node *l1=reverse(first);
        Node *l2=reverse(second);
            
        int carry=0,sum=0;
        Node *third=NULL,*l3=third;
        while(l1 && l2)
        {
            Node *newnode=new Node(0);
            if(third==NULL)
                third=newnode;
            else
                l3->next=newnode;
            l3=newnode;
            sum=l1->data + l2->data+carry;
            carry=sum/10;
            sum=sum%10;
            l3->data=sum;
            l1=l1->next;
            l2=l2->next;
            
        }
        while(l1)
        {
            Node *newnode= new Node(0);
            l3->next=newnode;
            l3=newnode;
            sum=l1->data+carry;
            carry=sum/10;
            sum=sum%10;
            l3->data=sum;
            l1=l1->next;
        }
        while(l2)
        {
            Node *newnode=new Node(0);
            l3->next=newnode;
            l3=newnode;
            sum=l2->data+carry;
            carry=sum/10;
            sum=sum%10;
            l3->data=sum;
            l2=l2->next;
        }
        if(carry!=0)
        {
            Node* newnode=new Node(carry);
            l3->next=newnode;
        }
        return reverse(third);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends