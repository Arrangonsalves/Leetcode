//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool CanWePlace(vector<int> &stalls,int dist,int k)
    {
        int cnt=1,last=stalls[0];
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-last>=dist)
            {
                cnt++;
                last=stalls[i];
            }
            if(cnt>=k)
                return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int low=0,high=stalls[n-1]-stalls[0];
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(CanWePlace(stalls,mid,k))
                low=mid+1;
            else
                high=mid-1;
        }
        return high;
        
        //TC:O(max-min * N)
        /*for(int i=1;i<stalls[n-1]-stalls[0];i++)
        {
            if(CanWePlace(stalls,i,k))
                continue;
            else
                return i-1;
        }*/
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends