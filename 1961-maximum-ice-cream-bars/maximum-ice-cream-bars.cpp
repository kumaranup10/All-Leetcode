class Solution {
public:
    // int can_buy(vector<int>&costs,int coin,int idx)
    // {
    //     if(idx==nums.size())
    //     return 1;
    //     return max
    // }
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());

        int idx=0,ans=0;
        while(idx < costs.size() && coins >= costs[idx])
        {
            coins -= costs[idx];
            ans++;
            idx++;
        }
        return idx;
    }
};