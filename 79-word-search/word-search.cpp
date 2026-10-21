class Solution {
private:
    bool solve(int i,int j,vector<vector<char>> &board,string word,vector<vector<int>> &vis,int idx,int n,int m) {
        if(idx==word.size()) return true;

        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1 || word[idx]!=board[i][j]) return false;

        vis[i][j]=1;

        bool ans=solve(i+1,j,board,word,vis,idx+1,n,m) ||
                 solve(i-1,j,board,word,vis,idx+1,n,m) ||
                 solve(i,j+1,board,word,vis,idx+1,n,m) ||
                 solve(i,j-1,board,word,vis,idx+1,n,m);

        vis[i][j]=0;

        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(solve(i,j,board,word,vis,0,n,m)) {
                    return true;
                }
            }
        }
        return false;
    }
};