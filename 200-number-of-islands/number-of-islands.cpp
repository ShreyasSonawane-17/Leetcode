class Solution {
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited){
        visited[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i<4; i++){
            int newr = row + dr[i];
            int newc = col + dc[i];

            if(newr >= 0 && newr<n &&
            newc >= 0 && newc<m &&
            grid[newr][newc] == '1' &&
            !visited[newr][newc]){
                dfs(newr, newc, grid, visited);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));
        int cnt = 0;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    cnt++;
                    dfs(i , j , grid , visited);
                }
            }
        }
        return cnt;
    }
};