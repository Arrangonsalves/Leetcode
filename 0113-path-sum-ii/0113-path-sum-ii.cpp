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
    void preorder(TreeNode* root,int targetSum,vector<vector<int>> &ans,int &sum,vector<int> &v)
    {
        if(root==NULL)
            return;
        sum+=root->val;
        v.push_back(root->val);
        if(sum==targetSum && root->left==NULL && root->right==NULL)
            ans.push_back(v);
        preorder(root->left,targetSum,ans,sum,v);
        preorder(root->right,targetSum,ans,sum,v);
        sum-=root->val;
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;
        vector<int> v;
        int sum=0;
        preorder(root,targetSum,ans,sum,v);
        return ans;
    }
};