class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDiff=0,curMin=10000,curMax=-10000;
        for(auto &i:arrays)
        {
            maxDiff=max(maxDiff,max(i.back()-curMin,curMax-i[0]));
            curMin=min(curMin,i[0]);
            curMax=max(curMax,i.back());
        }
        return maxDiff;
    }
};