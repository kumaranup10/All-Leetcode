class Solution {
public:
    bool find(int n)
    {
        if(n <= 1) return false;
        if(n == 2 || n == 3) return true;

        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0)
                return false;
        }
        return true;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int first = -1;
        int last = -1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(find(nums[i]))
            {
                if(first == -1)
                    first = i;
                last = i;
            }
        }

        return last - first;
    }
};