class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n),right(n);
        left[0]=INT_MIN;
        for(int i=1;i<nums.size();i++)
            {
                left[i]=max(left[i-1],nums[i-1]);
            }
        right[n-1]=INT_MIN;
        for(int i=n-2;i>=0;i--)
            {
                right[i]=max(right[i+1],nums[i+1]);
            }

        vector<int>ans;

        for(int i=0;i<n;i++)
            if(nums[i]>left[i] || nums[i]>right[i])
                ans.push_back(nums[i]);
        return ans;
    }
};