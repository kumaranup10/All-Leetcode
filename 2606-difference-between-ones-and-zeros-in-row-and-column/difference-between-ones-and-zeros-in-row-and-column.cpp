class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> v1r(n, vector<int>(m)), v0r(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            int count0 = 0, count1 = 0;

            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) count0++;
                if(grid[i][j] == 1)count1++;
            }

            for(int j = 0; j < m; j++) {
                v1r[i][j] = count1;
                v0r[i][j] = count0;
            }
        }

        vector<vector<int>> v1c(n, vector<int>(m)), v0c(n, vector<int>(m));

        for(int j = 0; j < m; j++) {
            int count0 = 0, count1 = 0;

            for(int i = 0; i < n; i++) {
                if(grid[i][j] == 0) count0++;
                if(grid[i][j] == 1) count1++;
            }

            for(int i = 0; i < n; i++) {
                v1c[i][j] = count1;
                v0c[i][j] = count0;
            }
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            vector<int> temp(m);

            for(int j = 0; j < m; j++) {
                temp[j] = v1r[i][j] + v1c[i][j] - v0r[i][j] - v0c[i][j];
            }

            ans.push_back(temp);
        }

        return ans;
    }
};