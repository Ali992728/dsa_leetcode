class Solution {
private:
    bool isCycleDFS(int src,int parent,vector<bool> &vis,vector<vector<int>> &adj) {
        vis[src]=true;

        for(auto v:adj[src]) {
            if(!vis[v]) {
                if(isCycleDFS(v,src,vis,adj)) {
                    return true;
                }
            }
            else if(v!=parent) {
                return true;
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        vector<vector<int>> adj(n+1);

        for(int i=0;i<n;i++) {
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool> vis(n+1,false);

            if(isCycleDFS(u,-1,vis,adj)) {
                return {u,v};
            }
        }

        return {};

    }
};