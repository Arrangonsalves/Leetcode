class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int n=start^goal;
        cout<<n;
        int cnt=0;
        while(n!=0)
        {
            if((n&1)!=0)
                cnt++;
            n=n>>1;
        }
        return cnt;
    }
};