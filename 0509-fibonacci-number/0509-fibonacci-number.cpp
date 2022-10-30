class Solution {
public:
    int fib(int n) {
        vector<int> fibb;
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        fibb.push_back(0);
        fibb.push_back(1);
        for(int i=2;i<=n;i++)
        {
            fibb.push_back(fibb[i-1]+fibb[i-2]);
        }
        return fibb[n];
        
    }
};