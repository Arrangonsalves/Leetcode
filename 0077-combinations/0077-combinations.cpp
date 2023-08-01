class Solution {
public:
    void solve(int ind,int n,int k,vector<int> &v,vector<vector<int>> &ans)
    {
        if(ind>n)
        {
            if(v.size()==k)
            {
                ans.push_back(v);
            }
            return;
        }
        v.push_back(ind);
        solve(ind+1,n,k,v,ans);
        v.pop_back();
        solve(ind+1,n,k,v,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int> v;
        solve(1,n,k,v,ans);
        return ans;
    }
};