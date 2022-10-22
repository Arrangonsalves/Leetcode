class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro=0;
        //int mini=*max_element(prices.begin(),prices.end());
        int mini=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<mini)
                mini=prices[i];
            if(prices[i]-mini>maxpro)
                maxpro=prices[i]-mini;
        }
        return maxpro;
    }
};