//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
            m[arr[i]]++;
        int ele=INT_MIN,mini=INT_MAX;
        for(auto i:m)
        {
            if(i.second<mini)
            {
               mini=i.second;
               ele=i.first;
            }
            else if(i.second==mini && i.first>ele)
                ele=i.first;
        }
        return ele;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends