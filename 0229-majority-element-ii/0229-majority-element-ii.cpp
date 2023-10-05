class Solution {
public:
    //Extended Boyer Moore’s Voting Algorithm
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,ele1,ele2;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt1==0 && nums[i]!=ele2)
            {
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1)
            {
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1)
                cnt1++;
            else if(nums[i]==ele2)
                cnt2++;
            else
            {
                cnt1--;cnt2--;
            }
        }
        vector<int> ans;
        cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ele1)
                cnt1++;
            else if(nums[i]==ele2)
                cnt2++;
        }
        int n=int(nums.size()/3);
        if(cnt1>n)
            ans.push_back(ele1);
        if(cnt2>n)
            ans.push_back(ele2);
        return ans;

        /*vector<int> ans;
        unordered_map<int,int> m;
        int n=floor(nums.size()/3);
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for(auto i:m)
        {
            if(i.second>n)
                ans.push_back(i.first);
        }
        return ans;*/
        
    }
};