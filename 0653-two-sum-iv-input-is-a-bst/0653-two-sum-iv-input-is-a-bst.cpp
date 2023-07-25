/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root,int k,unordered_map<int,int> &m,bool &ans)
    {
        if(root!=NULL)
        {
            if(m.find(k-root->val)!=m.end())
            {
                ans=true;
                return;
            }
            m[root->val]++;
            preorder(root->left,k,m,ans);
            preorder(root->right,k,m,ans);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        
        unordered_map<int,int> m;
        bool ans=false;
        preorder(root,k,m,ans);
        return ans;
    }
};