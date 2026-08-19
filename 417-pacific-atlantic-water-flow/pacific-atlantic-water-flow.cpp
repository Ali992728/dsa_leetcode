class Solution {
private:
    void dfs(int i,int j,vector<vector<int>> &heights,vector<vector<int>> &ocean,int n,int m,int prev) {
        if(i<0 || j<0 || i>=n || j>=m || ocean[i][j] || heights[i][j]<prev) return;

        ocean[i][j]=1;

        dfs(i+1,j,heights,ocean,n,m,heights[i][j]);
        dfs(i-1,j,heights,ocean,n,m,heights[i][j]);
        dfs(i,j+1,heights,ocean,n,m,heights[i][j]);
        dfs(i,j-1,heights,ocean,n,m,heights[i][j]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> ans;
        if(n==0) return ans;

        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));

        for(int i=0;i<n;i++) {
            dfs(i,0,heights,pacific,n,m,INT_MIN);
            dfs(i,m-1,heights,atlantic,n,m,INT_MIN);
        }

        for(int j=0;j<m;j++) {
            dfs(0,j,heights,pacific,n,m,INT_MIN);
            dfs(n-1,j,heights,atlantic,n,m,INT_MIN);
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pacific[i][j]==1 && atlantic[i][j]==1) {
                    vector<int> v(2);
                    v[0]=i;
                    v[1]=j;
                    ans.push_back(v);
                }
            }
        }

        return ans;
    }
};