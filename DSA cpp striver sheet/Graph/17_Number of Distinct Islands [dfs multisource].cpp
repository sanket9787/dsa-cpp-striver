class Solution {
public:
    void DFS(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,-1,1};
  
        while(!q.empty()){
            auto first = q.front().first;
            auto sec = q.front().second;
            q.pop();

            for(int k = 0; k<4; k++){
                int nrow = first + dr[k];
                int ncol = sec + dc[k];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    DFS(i, j, grid, vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};