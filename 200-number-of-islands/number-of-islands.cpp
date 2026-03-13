class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]=='1'){

                    ans++;
                    q.push({i,j});
                    grid[i][j]='0';

                    while(!q.empty()){

                        auto [x,y] = q.front();
                        q.pop();

                        for(int d=0; d<4; d++){

                            int nx = x + dx[d];
                            int ny = y + dy[d];

                            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='1'){
                                q.push({nx,ny});
                                grid[nx][ny]='0';
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};