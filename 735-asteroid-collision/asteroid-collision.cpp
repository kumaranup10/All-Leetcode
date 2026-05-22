class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;

        for(auto i:asteroids)
        {
            bool des=false;
            while(!s.empty() && i<0 && s.top()>0)
            {
                int sum=i+s.top();

                if(sum==0)
                {
                    s.pop();
                    des=true;
                    break;
                }
                else if(sum>0)
                {
                    des=true;
                    break;
                }
                else 
                s.pop();
            } 
            if(!des && i!=0)
            s.push(i);
        }
        vector<int>ans;

        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};