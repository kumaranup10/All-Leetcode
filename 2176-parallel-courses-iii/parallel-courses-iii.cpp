class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relation, vector<int>& time) {
        vector<int>adj[n],indeg(n);
        for(int i=0;i<relation.size();i++)
        {
            adj[relation[i][0]-1].push_back(relation[i][1]-1);
            indeg[relation[i][1]-1]++;
        }
        vector<int>ans(n,0);
        queue<int>q;
        for(int i=0;i<n;i++)
        if(indeg[i]==0)
        {
            q.push(i);
            ans[i]=time[i];
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int j=0;j<adj[node].size();j++)
            {
                indeg[adj[node][j]]--;
                if(!indeg[adj[node][j]])
                q.push(adj[node][j]);
                ans[adj[node][j]]=max(ans[adj[node][j]],ans[node]+time[adj[node][j]]);
            }

        }
        int mini=INT_MIN;
        for(auto i:ans)
        {
            mini=max(mini,i);
        }
        return mini;
    }
};