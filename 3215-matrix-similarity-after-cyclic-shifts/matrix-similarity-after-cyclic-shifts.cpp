class Solution {
public:
    bool areSimilar(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int newIndex;

                // even row → left shift
                if (i % 2 == 0)
                    newIndex = (j + k) % m;
                else
                    newIndex = (j - k % m + m) % m;

                if (grid[i][j] != grid[i][newIndex])
                    return false;
            }
        }

        return true;
    }
};