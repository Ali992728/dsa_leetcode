class Solution {
private:
    bool isPossible(int i,int j,int mid,vector<vector<bool>> &vis,int n,vector<vector<int>> &grid) {
        if(i<0 || j<0 || i>=n || j>=n || vis[i][j] || grid[i][j]>mid) return false;

        if(i==n-1 && j==n-1) return true;

        vis[i][j]=true;

        if(isPossible(i+1,j,mid,vis,n,grid)) return true;
        if(isPossible(i-1,j,mid,vis,n,grid)) return true;
        if(isPossible(i,j+1,mid,vis,n,grid)) return true;
        if(isPossible(i,j-1,mid,vis,n,grid)) return true;

        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;

        int l=grid[0][0];
        int h=n*n-1;

        while(l<=h) {
            int mid=l+(h-l)/2;

            vector<vector<bool>> vis(n,vector<bool>(n,false));

            if(isPossible(0,0,mid,vis,n,grid)) {
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
    }
};