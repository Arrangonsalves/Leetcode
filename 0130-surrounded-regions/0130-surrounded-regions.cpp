class Solution {
public:
    void dfs(int r,int c,vector<vector<char>> &board,vector<vector<int>> &vis)
    {
        vis[r][c]=1;
        int n=board.size();
        int m=board[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nr=r+drow[i];
            int nc=c+dcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='O')
                dfs(nr,nc,board,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        for(int j=0;j<m;j++)
        {
            //first row
            if(board[0][j]=='O' && !vis[0][j])
                dfs(0,j,board,vis);
            //last row
            if(board[n-1][j]=='O' && !vis[n-1][j])
                dfs(n-1,j,board,vis);
        }
        for(int i=0;i<n;i++)
        {
            //first column
            if(board[i][0]=='O' && !vis[i][0])
                dfs(i,0,board,vis);
            //last column
            if(board[i][m-1]=='O' && !vis[i][m-1])
                dfs(i,m-1,board,vis);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};