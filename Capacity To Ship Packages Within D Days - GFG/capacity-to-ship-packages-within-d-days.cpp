//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool possible(int weights[],int days,int cap,int N)
    {
        int d=1,sum=0;
        for(int i=0;i<N;i++)
        {
            if(sum+weights[i]<=cap)
                sum+=weights[i];
            else
            {
                sum=weights[i];
                d++;
            }
        }
        return d<=days;
    }
    int leastWeightCapacity(int weights[], int N, int days) {
        // code here
        //TC:O(N* log(sum-max))
        int low=*max_element(weights,weights+N);
        int high=accumulate(weights,weights+N,0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(possible(weights,days,mid,N))
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends