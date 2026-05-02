class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if(nums.size()<=1)
        return 0;

        int n = nums.size();
        long long sum = 0, F = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            F += (long long)i * nums[i];
        }

        long long ans = F;
        for(int k = 1; k < n; k++){
            F = F + sum - (long long)n * nums[n - k];
            ans = max(ans, F);
        }

        return ans;
    }
};