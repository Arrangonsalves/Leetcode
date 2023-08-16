class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<=(1<<n)-1;i++)
        {
            vector<int> ds;
            for(int bit=0;bit<n;bit++)
            {
                if(i&(1<<bit))
                    ds.push_back(nums[bit]);
            }
            ans.push_back(ds);
        }
        return ans;


        /*vector<vector<int>> v={{}};
        for(int num:nums)
        {
            int n=v.size();
            for(int i=0;i<n;i++)
            {
                v.push_back(v[i]);
                v.back().push_back(num);
            }
        }
        return v;*/
    }
};