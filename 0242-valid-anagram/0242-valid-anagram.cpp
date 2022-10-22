class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()<t.size() || s.size()>t.size())
            return false;
        int arr[26]={0};
        for(int i=0;i<t.size();i++)
            arr[t[i]-'a']++;
        for(int i=0;i<s.size();i++)
        {
            //arr[s[i]-'a']=arr[s[i]-'a']-1;
            if(--arr[s[i]-'a']<0)
                return false;
        }
        return true;
    }
};