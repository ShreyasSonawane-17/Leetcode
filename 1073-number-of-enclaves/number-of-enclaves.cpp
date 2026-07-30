class Solution {
    void dfs(int row, int col, vector<vector<int>>& grid,  vector<vector<int>>& visited ){
        visited[row][col] = 1;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i = 0; i<4 ; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nr<grid.size() &&
            nc>= 0 && nc<grid[0].size() &&
            grid[nr][nc] == 1 && !visited[nr][nc]){
                dfs(nr,nc,grid,visited);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

       vector<vector<int>> visited(n , vector<int>(m,0));

        for(int j = 0; j<m ; j++){
            //first row
            if(grid[0][j] == 1 && !visited[0][j]){
                dfs(0,j,grid,visited);
            }
            //last row
            if(grid[n-1][j] == 1 && !visited[n-1][j]){
                dfs(n-1,j,grid,visited);
            }
        }

        for(int i = 0; i<n ; i++){
            //first col
            if(grid[i][0] == 1 && !visited[i][0]){
                dfs(i,0,grid,visited);
            }
            //last col
            if(grid[i][m-1] == 1 && !visited[i][m-1]){
                dfs(i,m-1,grid,visited);
            }
        }

        int cnt = 0;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};