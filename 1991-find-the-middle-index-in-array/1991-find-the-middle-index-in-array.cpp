class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
         int sum=0,s=0;
        for(int i=0;i<nums.size();i++)
            sum=sum+nums[i];
        for(int i=0;i<nums.size();i++)
        {
            s=s+nums[i];
            if(sum==s)
                return i;
            sum=sum-nums[i];
        }
        return -1;
    }
};