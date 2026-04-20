class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        unordered_map<int, int> freq;
        
        // Count frequency
        for (auto& row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }
        int miss,rep;
        for (int i = 1; i <= total; i++) {
            if (freq[i] == 2) miss=i;
            else if (freq[i] == 0) rep=i;
        }
        
        return {miss,rep};
    }
};