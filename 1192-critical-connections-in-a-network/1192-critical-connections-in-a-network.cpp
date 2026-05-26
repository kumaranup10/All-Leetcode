class Solution {
public:
    void dfs(int node,int parent, int count, vector<vector<int>>&adj,
    vector<vector<int>>&bridge, vector<int>&discovery,
    vector<int>&low, vector<bool>&vis)
    {
        low[node]=discovery[node]=count;
        vis[node]=1;

        for(int i=0;i<adj[node].size();i++)
        {
            int neg=adj[node][i];
            if(neg==parent)
            continue;
            else if(vis[neg])
            {
                low[node]=min(low[node],discovery[neg]);
            }
            else
            {
                count++;
                dfs(neg,node,count,adj,bridge,discovery,low,vis);
                if(discovery[node]<low[neg])
                bridge.push_back({node,neg});
            }
            low[node]=min(low[neg],low[node]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n),bridge;

        for(auto e:connections)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>discovery(n),low(n);/* where discovery show that for the first time whenever the node is visited it is just like timer when the node come from starting from 1 second */
        vector<bool>vis(n,0);
        int count=0;
        dfs(0,-1,count,adj,bridge,discovery,low,vis);

        return bridge;


    }
};