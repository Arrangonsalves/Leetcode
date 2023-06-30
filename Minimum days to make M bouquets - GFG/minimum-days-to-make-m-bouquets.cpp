//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool possible(vector<int> &bloomDay,int i,int k,int m)
    {
        int cnt=0,ans=0;
        for(int j=0;j<bloomDay.size();j++)
        {
            if(bloomDay[j]<=i)
                cnt++;
            else
            {
                ans+=cnt/k;
                cnt=0;
            }
        }
        ans+=cnt/k;
        return ans>=m;
    }
    int solve(int m, int k, vector<int> &bloomDay){
      // Code here
      int n=bloomDay.size();
        if((long long)m*k>n)
            return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,k,m))
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
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends