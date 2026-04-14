class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>m;

        for(int i=0;i<nums.size();i++)
        m[nums[i]].push_back(i);

        int ans = INT_MAX;

        for (auto &it : m) {
            vector<int> &temp = it.second;

            if (temp.size() >= 3) {
                for (int i = 0; i + 2 < temp.size(); i++) {
                    int dist = 2 * (temp[i+2] - temp[i]);
                    ans = min(ans, dist);
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};