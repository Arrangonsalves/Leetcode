//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> findXandY(int A , int B , int N) {
        // code here
       for(int x=0; x<=N/A; x++)
       {
           for(int y=0; y<=N/B; y++)
           {
               if(N == (A*x) +(B*y))
                   return {x,y};
           }
       }
       return {-1,-1};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int A,B,N;
        
        cin>>A>>B>>N;

        Solution ob;
        vector<int> ans = ob.findXandY(A,B,N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends