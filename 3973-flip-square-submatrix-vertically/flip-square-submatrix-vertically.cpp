class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int top = x;
        int bottom = x + k - 1;

        while(top < bottom)
        {
            int col = y;

            while(col < y + k)
            {
                swap(grid[top][col], grid[bottom][col]);
                col++;
            }

            top++;
            bottom--;
        }

        return grid;
    }
};