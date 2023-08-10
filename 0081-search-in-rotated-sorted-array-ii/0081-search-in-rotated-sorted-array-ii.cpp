class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        //TC: Average case:O(logn) Worst case:O(n)
        int low = 0;
        int high = nums.size() - 1;
        while(low<=high)
        {
            int mid = low + (high-low) / 2;
            if (nums[mid] == target)
                return true;

			// with duplicates we can have this condition, just update left & right
            if((nums[low] == nums[mid]) && (nums[high] == nums[mid]))
            {
                low++;
                high--;
            }
			
			// first half is in order
            else if(nums[low] <= nums[mid])
            {
				// target is in first  half
                if((nums[low] <= target) && (nums[mid] >= target))
                    high = mid - 1;
                else
                    low = mid + 1;
            }
			
			// second half is order
            else
            {
                // target is in second half
                if((nums[mid] <= target) && (nums[high]>= target))
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};