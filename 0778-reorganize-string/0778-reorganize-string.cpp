class Solution {
public:
    string reorganizeString(string s) {
        
        vector<int> cnt(26);
        int mostFreq=0,j=0;

        for(char i:s)
        {
            if(++cnt[i-'a']>cnt[mostFreq])
                mostFreq=(i-'a');
        }
        if(2 * cnt[mostFreq]-1> s.size())
            return "";

        while(cnt[mostFreq])
        {
            s[j]=('a'+mostFreq);
            j+=2;
            cnt[mostFreq]--;
        }    
        
        for(int k=0;k<26;k++)
        {
            while(cnt[k])
            {
                if(j>=s.size())
                    j=1;
                s[j]=('a'+ k);
                cnt[k]--;
                j+=2;
            }
        } 
        return s;
    }
};