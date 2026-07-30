class Solution {
    void dfs(int row, int col , vector<vector<int>>& grid, vector<vector<int>>& visited){
        visited[row][col] = 1;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i = 0; i<4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr>=0 && nr<grid.size() &&
            nc>= 0 && nc<grid[0].size() &&
            !visited[nr][nc] && grid[nr][nc] == 0 ){
                dfs(nr,nc,grid,visited);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector(m,0));

        for(int j = 0; j<m ; j++){
            //first row
            if(grid[0][j] == 0 && !visited[0][j]){
                dfs(0,j,grid,visited);
            }
            //last row
            if(grid[n-1][j] == 0 && !visited[n-1][j]){
                dfs(n-1,j,grid,visited);
            }
        }

        for(int i = 0; i<n ; i++){
            //first col
            if(grid[i][0] == 0 && !visited[i][0]){
                dfs(i,0,grid,visited);
            }
            //last col
            if(grid[i][m-1] == 0 && !visited[i][m-1]){
                dfs(i,m-1,grid,visited);
            }
        }
        int cnt = 0;
        for(int i = 0; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(!visited[i][j] && grid[i][j] == 0){
                    cnt++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return cnt;
    }
};