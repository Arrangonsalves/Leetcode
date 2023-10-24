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
    /*int height(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }*/
    int check(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lh=check(root->left);
        int rh=check(root->right);
        if(rh==-1 || lh==-1)
            return -1;
        if(abs(rh-lh)>1)
            return -1;
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        //TC: O(N^2)
        //SC: O(N)
        /*if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL)
            return true;
        int a=(height(root->left)+1)-(height(root->right)+1);
        if(a==0 || a==1 || a==-1)
             return (isBalanced(root->left) &&(isBalanced(root->right)));
        return false;*/

        //TC:O(N)
        //SC:O(N)
        return check(root)!=-1;       
    }
};