class Solution {
public:
    void solve(int index,string &s,string digits,string mapping[],vector<string> &ans)
    {
        if(index==digits.size())
        {
            ans.push_back(s);
            return;
        }
        int number=digits[index]-'0';
        string value=mapping[number];
        for(int i=0;i<value.size();i++)
        {
            s.push_back(value[i]);
            solve(index+1,s,digits,mapping,ans);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)
            return ans;
        string s;
        int index=0;
        string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(index,s,digits,mapping,ans);
        return ans;
    }
};