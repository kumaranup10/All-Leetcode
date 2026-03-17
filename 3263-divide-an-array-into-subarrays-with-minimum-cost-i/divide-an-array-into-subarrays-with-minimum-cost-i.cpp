class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first=nums[0];
        int sec=INT_MAX,third=INT_MAX;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<sec)
            {
                third=sec;
                sec=nums[i];
            }
            else if(nums[i]<third)
            {
                third=nums[i];
            }
        }
        return first+sec+third;
    }
};