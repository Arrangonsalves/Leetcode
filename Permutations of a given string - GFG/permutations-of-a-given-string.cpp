//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void findPerm(string &S,string &str,set<string> &ans,vector<int> &freq)
	    {
	        if(str.size()==S.size())
	        {
	            ans.insert(str);
	            return;
	        }
	        for(int i=0;i<S.size();i++)
	        {
	            if(freq[i]==0)
	            {
	                str.push_back(S[i]);
	                freq[i]=1;
	                findPerm(S,str,ans,freq);
	                freq[i]=0;
	                str.pop_back();
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> ans;
		    string str="";
		    vector<int> freq(S.size(),0);
		    findPerm(S,str,ans,freq);
		    vector<string> v(ans.begin(),ans.end());
		    return v;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends