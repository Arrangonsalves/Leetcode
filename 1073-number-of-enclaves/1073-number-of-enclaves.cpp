class Solution {
public:
    
    int numEnclaves(vector<vector<int>>& grid) {
       int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            if(grid[0][i] && !vis[0][i])
            {
                q.push({0,i});
                vis[0][i]=1;
            }
                
            if(grid[n-1][i] && !vis[n-1][i])
            {
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(grid[i][0] && !vis[i][0])
            {
                q.push({i,0});
                vis[i][0]=1;
            }    
            if(grid[i][m-1] && !vis[i][m-1])
            {
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        int dr[]={-1,0,+1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1)
                {
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
};