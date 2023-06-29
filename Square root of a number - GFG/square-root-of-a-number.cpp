//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here
        if(x==1) return 1;
        int low=2,high=x/2;
        while(low<=high)
        {
            long long int mid=(low+high)/2;
            long long int pro=mid*mid;
            if(pro==x)
                return mid;
            else if(pro<x)
                low=mid+1;
            else
                high=mid-1;
        }
        return low-1;
        
        
        
        
        //O(N)
        /*long long int i=1;
        if(x==1) return 1;
        for(;i<=x/2;i++)
        {
            if(i*i==x)
                return i;
            if(i*i>x)
                break;
        }
        return i-1;*/
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends