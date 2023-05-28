//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        bool isNegative = (str[0] == '-');
        int ans = 0;
        for (int i = isNegative; i < str.size(); i++)
        {
            if ((str[i] - '0') >= 0 and (str[i] - '0') <= 9)
                ans = ans * 10 + (str[i] - '0');
            else
                return -1;
        }
        return isNegative ? -ans : ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends