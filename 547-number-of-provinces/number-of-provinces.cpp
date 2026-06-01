class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis)
    {
        if(vis[node]==1)
        return ;
        vis[node]=1;

        for(int i=0;i<adj[node].size();i++)
        {
            int neb=adj[node][i];
            dfs(neb,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        vector<bool>vis(n,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    int u=i;
                    int v=j;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                count++;
            }
        }
        return count;
    }
};