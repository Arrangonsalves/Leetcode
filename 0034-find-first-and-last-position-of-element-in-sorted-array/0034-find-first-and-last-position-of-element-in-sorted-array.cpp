class Solution {
public:
    int LowerBound(vector<int> &arr,int target)
    {
        int low=0,high=arr.size()-1;
        int ans=arr.size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]>=target)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
    int UpperBound(vector<int> &arr,int target)
    {
        int low=0,high=arr.size()-1;
        int ans=arr.size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]>target)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        //Linear Search
        //TC:O(N)
        //Sc:O(1)
        /*int first=-1,last=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                if(first==-1)
                    first=i;
                last=i;
            }
        }
        return {first,last};*/


        //Binary Search
        //TC:O(2LogN)
        //SC:O(1)
        int lb=LowerBound(nums,target);
        if(lb==nums.size() || nums[lb]!=target)
            return{-1,-1};
        return {lb,UpperBound(nums,target)-1};
        
        
        /*vector<int> v;
        v.push_back(-1);
        v.push_back(-1);
        int i=0,j=nums.size()-1;
        if(nums.size()==0)
            return v;
        if(nums.size()==1){
            if(nums[0]==target)
            {
                v[0]=0;
                v[1]=0;
            }
            return v;
        }     
        while(i<=j)
        {
            int mid=(i+j)/2;
            if(nums[mid]==target){
               int k=mid;
               if(mid>=i){
                   while(mid>=0 && nums[mid]==target)
                       mid--;
                    v[0]=mid+1;
               }
                
               if(k<=j){
                   while(k<nums.size() && nums[k]==target)
                       k++;
                   v[1]=k-1;
               }  
                break;
            }
            else if(nums[mid]<target)
                i=mid+1;
            else if(nums[mid]>=target)
                j=mid-1;
        }
        return v;*/
        
    }
};