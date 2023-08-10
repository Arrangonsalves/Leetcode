class Solution {
public:
    bool dfs(int node,int Col,vector<int> &color,vector<vector<int>> &graph)
    {
        color[node]=Col;
        for(auto i:graph[node])
        {
            if(color[i]==-1)
            {
                if(dfs(i,!Col,color,graph)==false)
                    return false;
            }
            else if(color[i]==Col)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        int m=graph[0].size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,0,color,graph)==false)
                    return false;
            }
        }
        return true;
    }
};