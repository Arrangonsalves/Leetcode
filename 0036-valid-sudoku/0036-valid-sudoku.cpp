class Solution {
public:
    bool isValid(int r,int c,char x,vector<vector<char>> &board)
    {
        for(int i=0;i<9;i++)
        {
            if(board[r][i]==x && i!=c)
                return false;
            if(board[i][c]==x && i!=r)
                return false;
            if(board[3*(r/3)+(i/3)][3*(c/3)+(i%3)]==x && 3*(r/3)+(i/3)!=r && 3*(c/3)+(i%3)!=c)
                return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n=board.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!='.')
                {
                    if(isValid(i,j,board[i][j],board)==false)
                        return false;
                }
            }
        }
        return true;
    }
};