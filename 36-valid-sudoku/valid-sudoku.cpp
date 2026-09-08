class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> boxes(9);

        for(int r=0;r<9;r++) {
            for(int c=0;c<9;c++) {
                if(board[r][c]=='.') continue;

                char value=board[r][c];

                int boxIndex=3*(r/3) + (c/3);

                if(row[r].count(value) || col[c].count(value) || boxes[boxIndex].count(value)) {
                    return false;
                }

                row[r].insert(value);
                col[c].insert(value);
                boxes[boxIndex].insert(value);
            }
        }

        return true;
    }
};