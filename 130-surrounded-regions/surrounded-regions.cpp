class Solution {
    void dfs(int row, int col ,vector<vector<char>>& board, vector<vector<int>>& visited){
        visited[row][col] = 1;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i = 0; i<4 ; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr>=0 && nr<board.size()&&
            nc>=0 && nc<board[0].size() &&
            !visited[nr][nc] && board[nr][nc] == 'O'){
                dfs(nr,nc,board,visited);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int j = 0; j<m ; j++){
            //first row
            if(board[0][j] == 'O' && !visited[0][j]){
                dfs(0,j,board,visited);
            }
            //last row
            if(board[n-1][j] == 'O' && !visited[n-1][j]){
                dfs(n-1,j,board,visited);
            }
        }
        for(int i = 0; i< n ; i++){
            //first col
            if(board[i][0] == 'O' && !visited[i][0]){
                dfs(i,0,board,visited);
            }
            //last col
            if(board[i][m-1] == 'O' && !visited[i][m-1]){
                dfs(i,m-1,board,visited);
            }
        }

        for(int i = 0; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};