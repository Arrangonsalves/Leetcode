class Solution {
public:
    bool isPossible(vector<int> &nums,int p,int diff)
    {
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]<=diff)
            {
                p--;
                i++;
            }
        }
        return p<=0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size(),left=0,right=nums[n-1]-nums[0];
        int ans=right;
        int maxi=INT_MIN;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(isPossible(nums,p,mid))
            {
                ans=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return ans;
    }
};