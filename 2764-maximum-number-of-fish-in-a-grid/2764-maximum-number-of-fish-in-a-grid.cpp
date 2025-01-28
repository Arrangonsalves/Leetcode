class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {

        int n= grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<int> dr={0,1,0,-1};
        vector<int> dc={1,0,-1,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]>0)
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    int f= grid[i][j];
                    grid[i][j]=0;
                    while(!q.empty())
                    {
                        auto curr=q.front();
                        q.pop();
                        for(int k=0;k<4;k++)
                        {
                            int nr=curr.first + dr[k];
                            int nc=curr.second + dc[k];
                            if(nr>= 0 && nr<n && nc>=0 && nc<m && grid[nr][nc] > 0)
                            {
                                f+=grid[nr][nc];
                                grid[nr][nc]=0;
                                q.push({nr,nc});
                            }
                        }
                    }
                    ans=max(ans,f);
                }
            }
        }
        return ans;
    }
};