class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0,j=arr.size()-1,s=0;
        for(int i=0;i<arr.size();i++)
            sum+=arr[i];
        if(sum%3!=0)
            return false;
        int part=0;
        for(int i=0;i<arr.size() && part<3;i++)
        {
            s+=arr[i];
            if(s==sum/3)
            {
                s=0;
                part++;
            }
        }
        if(part==3) return true;
        return false;
    }
};
