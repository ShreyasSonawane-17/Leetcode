class Solution {
    void dfs(int row, int col , vector<vector<int>>& grid, vector<vector<int>>& visited, int& cnt){
        visited[row][col] = 1;
        cnt++;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i = 0; i<4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nr<grid.size() &&
            nc >= 0 && nc<grid[0].size() &&
            grid[nr][nc] == 1 && !visited[nr][nc]){
                dfs(nr, nc , grid, visited, cnt);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i = 0; i<n; i++){
            
            for(int j = 0; j<m ; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int cnt = 0;
                    
                    dfs(i,j,grid,visited,cnt);
                    maxi = max(cnt,maxi);//should be below dfs as it gets cnt++ in dfs
                }
            }
        }
        return maxi;

    }
};