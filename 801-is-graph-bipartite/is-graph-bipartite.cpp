class Solution {
public:
    bool bpt(vector<vector<int>>&adj,vector<int>&color,int source)
        {
            for(int i=0;i<adj[source].size();i++)
            {
                // if neghbour is not coloured
                if(color[adj[source][i]]==-1)
                {
                    color[adj[source][i]]=(color[source]+1)%2;
                    if(!bpt(adj,color,adj[source][i]))
                    return 0;
                }
                // if coloured
                else
                {
                    if(color[adj[source][i]]==color[source])
                    return 0;
                }
            }
            return 1;
        }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        
        
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            color[i]=0;
            if(!bpt(graph,color,i))
            return 0;
        }
        return 1;
    }
};