class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<char>> row, col;
        map<pair<int,int>, set<char>> grid;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '.')
                    continue;
                pair<int, int> key = {i/3, j/3};

                if(row[i].count(board[i][j]) || col[j].count(board[i][j]) || grid[key].count(board[i][j]))
                    return false;

                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                grid[key].insert(board[i][j]);
            }

        }
        return true;
    }
};
