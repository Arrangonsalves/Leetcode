//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &arr) 
    {
        unordered_map<int,int> m;
        int ans=0,l=0,r=0;
        while(r<N)
        {
            m[arr[r]]++;
            if(m.size()<=2)
                ans=max(ans,r-l+1);
            else if(m.size()>2)
            {
                m[arr[l]]--;
                if(m[arr[l]]==0)
                    m.erase(arr[l]);
                l++;
            }
            r++;
        }
        return ans;
         
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends