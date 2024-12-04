class Solution {
public:
    bool issub(string &str1,string &str2)
    {
        int n=str1.size();
        int m=str2.size();
        int i=0,j=0;
        while(i<n && j<m)
        {
            char a=str1[i];
            char b=str2[j];
            char c;
            if(str2[j]=='z')
                c='a';
            else
                c=str2[j]+1;
            if(a==b ||c==a)
                i++;
            j++;
        }
        return i==n;
    }
    bool canMakeSubsequence(string str1, string str2) {
       return issub(str2,str1);
    }
};