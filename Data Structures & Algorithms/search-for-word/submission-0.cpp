class Solution {
public:
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    bool dfs(int x, int y, vector<vector<char>>& board, string& word, int index)
    {
        char temp;
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
            return false;
        if(board[x][y] != word[index])
            return false;
        else
        {
            temp = word[index];
            index++;
            board[x][y] = '#';
        }
            
        if(index == word.size())
            return true;
        
        bool ans = false;
        for(int i = 0; i <= 3; i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            ans = dfs(nx, ny, board, word, index) || ans;
        }
        board[x][y] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
       for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(dfs(i, j, board, word, 0))
                    return true;    
            }
        }
        return false; 
    }
};
