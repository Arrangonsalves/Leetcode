class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n=A.size(),cnt=0;
        unordered_map <int,int> m1,m2;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(m1.find(B[i])!=m1.end())
                cnt++;
            if(m2.find(A[i])!=m2.end())
                cnt++;
            if(A[i]==B[i])
                cnt++;
            m1[A[i]]=i;
            m2[B[i]]=i;
            ans.push_back(cnt);
        }
        return ans;
    }
};