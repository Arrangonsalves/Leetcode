//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        if(N==0 || (N&(N-1))!=0)
            return-1;
        return log2(N)+1;
        
        
       if(N == 0) return (-1);
       int cnt = 0;
       int pos = -1;
       for(int i = 31; i >= 0; i--)
       {
           int bit = (N>>i) & 1;
           if(bit == 1) cnt++, pos = i+1;
           if(cnt > 1) return (-1);
       }
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends