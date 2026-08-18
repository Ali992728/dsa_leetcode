class Solution {
private:
    int dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid,int n,int m,int &cnt) {
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]==0) return 0;

        vis[i][j]=1;
        cnt++;

        dfs(i+1,j,vis,grid,n,m,cnt);
        dfs(i-1,j,vis,grid,n,m,cnt);
        dfs(i,j+1,vis,grid,n,m,cnt);
        dfs(i,j-1,vis,grid,n,m,cnt);

        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int cnt=0;
                if(!vis[i][j] && grid[i][j]==1) {
                    dfs(i,j,vis,grid,n,m,cnt);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};