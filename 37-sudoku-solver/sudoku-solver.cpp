class Solution {
public:
    bool check(int num,int i,int j,vector<vector<char>>& board)
    {
        char n='0'+num;
        // for row
        for(int row=0;row<9;row++)
        if(board[row][j]==n)
        return 0;

        // for col
        for(int col=0;col<9;col++)
        if(board[i][col]==n)
        return 0;

        // for block
        int row=i/3*3,col=j/3*3;

        for(int r=row;r<row+3;r++)
        for(int c=col;c<col+3;c++)
        if(board[r][c]==n)
        return 0;


        return 1;

    }
    bool find(int i,int j,vector<vector<char>>& board)
    {
        if(i==9)
        return 1;
        if(j==9)
        return find(i+1,0,board);

        if(board[i][j]!='.')
        return find(i,j+1,board);

        for(int num=1;num<10;num++)
        {
            if(check(num,i,j,board))
            {
                board[i][j]='0'+num;
                if(find(i,j+1,board))
                    return 1;
                board[i][j]='.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool need=find(0,0,board);
    }
};