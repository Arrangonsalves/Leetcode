//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long calchrs(vector<int> &piles,int mid)
    {
        long long hrs = 0;
        for (int i = 0; i < piles.size(); i++)
            hrs+= ceil(piles[i] / (double)mid);
        return hrs;
    }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long hrs=calchrs(piles,mid);
            if(hrs<=H)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends