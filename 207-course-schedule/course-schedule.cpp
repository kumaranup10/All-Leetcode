class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses,p=prerequisites.size();
        vector<int>indeg(n,0);
        vector<vector<int>>adj(n);
        
        for(int i=0;i<p;i++)
        {
            indeg[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        // now push into queue 
        queue<int>q;
        
        for(int i=0;i<n;i++)
        if(!indeg[i])
        q.push(i);
        
        
        int count=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            for(int j=0;j<adj[node].size();j++)
            {
                int neighbor = adj[node][j];
                indeg[neighbor]--;
            
                if(indeg[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        return count==n;
    }
};