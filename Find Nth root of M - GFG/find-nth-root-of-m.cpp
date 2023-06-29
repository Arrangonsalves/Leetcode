//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    //return 1 if ==m
    //return 0 if <m
    //return 2 if >m
    int fun(int mid,int n,int m)
    {
        long long ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=ans*mid;
            if(ans>m)
                return 2;
        }
        if(ans==m)
            return 1;
        return 0;
    }
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int low=1,high=m;
	    while(low<=high)
	    {
	        int mid=(low+high)/2;
	        int p=fun(mid,n,m);
	        if(p==1)
	            return mid;
	        else if(p==0)
	            low=mid+1;
	        else
	            high=mid-1;
	    }
	    return -1;
	    
	    
	    
	    
	    
	    //TC:O(M*N)
	    /*if(m==1) return 1;
	    for(int i=1;i<=m;i++)
	    {
	        long long int pro=1;
	        if(pow(i,n)==m)
	            return i;
	    }
	    return -1;*/
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends