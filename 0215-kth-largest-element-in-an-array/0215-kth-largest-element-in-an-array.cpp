class Solution {
public:
    int partition(vector<int> &nums,int low,int high)
    {
        int i=low,j=low,pivot=high,n=high;
        while(i<=n)
        {
            if(nums[pivot]>nums[i])
                swap(nums[i],nums[j++]);
            i++;
        }
        swap(nums[j],nums[pivot]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
    
        int r=nums.size()-k, low=0,high=nums.size()-1;
        while(true)
        {
            int pivot_pos=partition(nums,low,high);
            if(pivot_pos==r)
                return nums[pivot_pos];
            if(pivot_pos<r)
                low=pivot_pos+1;
            else
                high=pivot_pos-1;
        }
        
        
        
        
        /*
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];*/
    }
};