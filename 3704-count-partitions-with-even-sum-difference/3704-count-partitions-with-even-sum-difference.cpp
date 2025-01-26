class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        int count=0,add=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            add+=nums[i];
            if(add%2 == (sum-add)%2)
                count++;
        }
        return count;
    }
};