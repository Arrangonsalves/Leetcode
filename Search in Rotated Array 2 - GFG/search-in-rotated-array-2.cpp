//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& arr, int Key) {
        // Code here
        int low=0,high=arr.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==Key)
                return 1;
            if(arr[mid]==arr[low] && arr[mid]==arr[high])
            {
                low++;
                high--;
                continue;
            }
            //left side is sorted
            else if(arr[low]<=arr[mid])
            {
                if(arr[low]<=Key && Key<=arr[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            //right side is sorted
            else
            {
                if(arr[mid]<=Key && Key<=arr[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return 0;
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
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends