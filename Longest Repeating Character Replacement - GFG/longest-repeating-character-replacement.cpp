//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        // code here
        int i=0,j=0,maxC=0,ans=-1;
            unordered_map<char,int> m;
            while(j<s.size())
            {
                m[s[j]]++;
                maxC=max(maxC,m[s[j]]);

                int curr_len=j-i+1;  //curr length of window
                if(curr_len - maxC>k) //the curr window has more than k replacable items case
                {
                    m[s[i]]--;
                    i++;   //shrinking the window
                }
                curr_len=j-i+1;
                ans=max(ans,curr_len);
                j++;
            }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends