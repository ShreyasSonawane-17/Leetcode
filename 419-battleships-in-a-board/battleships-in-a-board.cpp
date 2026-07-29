class Solution {
    void dfs(int row, int col, vector<vector<char>>& board,vector<vector<int>>& visited){
        visited[row][col] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0,1,0,-1};

        for(int i = 0; i<4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr>= 0 && nr<board.size() &&
            nc >= 0 && nc<board[0].size() &&
            board[nr][nc] == 'X' && !visited[nr][nc]){
                dfs(nr,nc,board,visited);
            }
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n , vector<int>(m,0));
        int cnt = 0;

        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(board[i][j] == 'X' && !visited[i][j]){
                    cnt++;
                    dfs(i,j,board,visited);
                }
            }
        }
        return cnt;
    }
};