//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int findIndex(int in[],int ele,int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        if(ele==in[i])
            return i;
    }
    return -1;
}
Node *constructTree(int in[],int ins,int ine,int post[],int ps,int pe)
{
    if(ins>ine || ps>pe)
        return NULL;
    Node* root=new Node(post[pe]);
    
    int inRoot=findIndex(in,post[pe],ins,ine);
    int numsleft=inRoot-ins;
    
    root->left=constructTree(in,ins,inRoot-1,post,ps,ps+numsleft-1);
    root->right=constructTree(in,inRoot+1,ine,post,ps+numsleft,pe-1);
    
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    return constructTree(in,0,n-1,post,0,n-1);
}
