class Solution {
public:
    bool check(int i,int j,vector<vector<char>>& board,char n)
    {
        for(int row=0;row<9;row++)
        if(board[row][j]==n)
        return 0;

        for(int col=0;col<9;col++)
        if(board[i][col]==n)
        return 0;

        int col=j/3*3,row=i/3*3;

        for(int r=row;r<row+3;r++)
        for(int c=col;c<col+3;c++)
        if(board[r][c]==n)
        return 0;

        return 1;
    }


    // bool find(int i,int j,vector<vector<char>>& board)
    // {
    //     if(i==9)
    //     return 1;
    //     if(j==9)
    //     return find(i+1,0,board);

    //     if(board[i][j]!='.')
    //     return find(i,j+1,board);

    //     for(int num=1;num<10;num++)
    //     {
    //         if(check(i,j,board,num))
    //         {
    //             board[i][j]='0'+num;
    //             if(find(i,j+1,board))
    //             return 1;
    //             board[i][j]='.';
    //         }
    //     }
    //     return 0;
    // }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    char val=board[i][j];
                    board[i][j]='.';
                    if(!check(i,j,board,val))
                    return false;
                    board[i][j]=val;
                }
            }
        }
        return true;
    }
};