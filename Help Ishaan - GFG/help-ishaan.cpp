//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    bool prime(int n)
	    {
	        for(int i=2;i<=n/2;i++)
	        {
	            if(n%i==0)
	                return false;
	        }
	        return true;
	    }
		int NthTerm(int N){
		    // Code here
		    if(N==1)
		        return 1;
		    if(prime(N))
		        return 0;
		    int l=N-1,r=N+1;
		    while(!prime(l))
		        l--;
		    while(!prime(r))
		        r++;
		    if(N-l<r-N)
		        return N-l;
		    return r-N;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		int ans = obj.NthTerm(N);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends