//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// To find minimum sum of unique elements.
long long int minSum(int arr[], int n);




int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSum(a, n) << endl;
        
    }
}
// } Driver Code Ends


long long int minSum(int arr[], int n)
{
	// Complete the function
	long long int sum=0;
	for(int i=0;i<n-1;i++)
	{
	    if(arr[i]>=arr[i+1])
	    {
	        while(arr[i]>=arr[i+1])
	            arr[i+1]++;
	    }
	    sum+=arr[i];
	}
	sum+=arr[n-1];
	return sum;
}