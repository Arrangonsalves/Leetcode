class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum,max=0;
        for(auto it: accounts){
            sum=0;
            for(int i=0;i<it.size();i++){
                sum+=it[i];
                if(max<sum)
                    max=sum;
            }
        }
        return max;
        
    }
};