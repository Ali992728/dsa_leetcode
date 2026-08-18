class Solution {
private:
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid,int n,int m) {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1' || vis[i][j]) return;

        vis[i][j]=1;

        dfs(i-1,j,vis,grid,n,m);
        dfs(i+1,j,vis,grid,n,m);
        dfs(i,j+1,vis,grid,n,m);
        dfs(i,j-1,vis,grid,n,m);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]=='1' && !vis[i][j]) {
                    dfs(i,j,vis,grid,n,m);
                    islands++;
                }
            }
        }
        return islands;
    }
};