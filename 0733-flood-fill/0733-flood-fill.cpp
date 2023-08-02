class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int same_color=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int row=r+delrow[i];
                int col=c+delcol[i];
                if(row>=0 && row<n && col>=0 && col<m && image[row][col]==same_color && image[row][col]!=color)
                {
                    image[row][col]=color;
                    q.push({row,col});
                }
            }
        }
        
        return image;
    }
};