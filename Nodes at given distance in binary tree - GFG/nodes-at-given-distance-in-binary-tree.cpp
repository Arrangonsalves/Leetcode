//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

    Node* parent(Node* root,unordered_map<Node*,Node*> &parent_track,int target)
    {
        queue<Node*> q;
        q.push(root);
        Node* ans;
        while(!q.empty())
        {
            Node* curr=q.front();
            q.pop();
            if(curr->data==target)
                ans=curr;
            if(curr->left)
            {
                parent_track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parent_track[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return ans;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        unordered_map<Node*,Node*> parent_track;
        Node* tar=parent(root,parent_track,target);
        
        queue<Node*> q;
        q.push(tar);
        unordered_map<Node*,bool> vis;
        vis[tar]=true;
        int lvl=0;
        while(!q.empty())
        {
            int size=q.size();
            if(lvl++==k)
                break;
            for(int i=0;i<size;i++)
            {
                Node* curr=q.front();
                q.pop();
                if(curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent_track[curr] && !vis[parent_track[curr]])
                {
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]]=true;
                }
            }
        }
        vector<int> res;
        while(!q.empty())
        {
            res.push_back(q.front()->data);
            q.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends