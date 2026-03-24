class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int>s;

        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                int height=heights[s.top()];
                s.pop();

                if(s.empty())
                ans=max(ans,height*i);
                else
                ans=max(ans,height*(i-s.top()-1));
            }
                s.push(i);
        }
        int n=heights.size();
        while(!s.empty())
        {
            int height=heights[s.top()];
            s.pop();
            if(s.empty())
            ans=max(ans,height*n);
            else
            ans=max(ans,height*(n-s.top()-1));
        }
        return ans;
    }
};