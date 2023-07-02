//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int stucnt(int A[],int N,int M,int maxalloc)
    {
        int sum=0,cnt=1;
        for(int i=0;i<N;i++)
        {
            if(sum+A[i]<=maxalloc)
                sum+=A[i];
            else
            {
                sum=A[i];
                cnt++;
            }
        }
        return cnt;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        //TC:O(sum-max+1 *N)
        if(M>N)
            return -1;
        int low=*max_element(A,A+N);
        int high=accumulate(A,A+N,0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            int cnt=stucnt(A,N,M,mid);
            if(cnt>M)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
            
            
            
            
            
        /*if(M>N)
            return -1;
        int start=*max_element(A,A+N);
        int end=accumulate(A,A+N,0);
        for(int i=start;i<=end;i++)
        {
            int cntstu=stucnt(A,N,M,i);
            //cout<<i<<" "<<cntstu<<endl;
            if(cntstu==M)
                return i;
        }
        return -1;*/
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends