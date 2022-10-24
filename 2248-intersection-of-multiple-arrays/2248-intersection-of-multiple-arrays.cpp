class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> v;
        unordered_set<int> s1(nums[0].begin(),nums[0].end());
        unordered_set<int> s2;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
               if(s1.find(nums[i][j])!=s1.end())
                   s2.insert(nums[i][j]);
            }
            s1.clear();
            s1=s2;
            s2.clear();
        }
        for(auto i:s1)
            v.push_back(i);
        sort(v.begin(),v.end());
        return v;
        
    }
};