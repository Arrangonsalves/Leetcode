//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
/*Node* merge(Node* l1,Node* l2)
{
    Node* l3=new Node(0);
    Node* curr=l3;
    
    while(l1 && l2)
    {
        if(l1->data<=l2->data)
        {
            curr->next=l1;
            l1=l1->next;
        }
        else
        {
            curr->next=l2;
            l2=l2->next;
        }
        curr=curr->next;
    }
    if(l1)
        curr->next=l1;
    if(l2)
        curr->next=l2;
    return l3->next;
}
void sort(Node **head)
{
     // Code here
     Node *temp=NULL;
     Node *slow=*head;
     Node *fast=*head;
     
     while(fast && fast->next)
     {
         temp=slow;
         slow=slow->next;
         fast=fast->next->next;
     }
     temp->next=NULL;
     Node *l1=sort(head);
     Node *l2=sort(slow);
     
     merge(l1,l2);
}*/
void sort(Node **head)
{
    //  // Code here
     Node* curr = *head;
     vector<int> v;
     
     while(curr){
         int val = curr->data;
         v.push_back(val);
         curr = curr->next;
     }
     
     
     Node* n = *head;
     
    sort(v.begin(), v.end());
    for(auto x: v){
        n->data = x;
        n = n->next;
    }
     

}