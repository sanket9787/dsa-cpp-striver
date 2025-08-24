class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int,int>> q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                        if(grid[i][j] == 1){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                } 
            }
        }

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,1,-1};

        while(!q.empty()){
            auto i = q.front().first;
            auto j = q.front().second;
            q.pop();
            
            for(int k = 0; k<4; k++){
                int nrow = i + dr[k];
                int ncol = j + dc[k];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }          
        }

        int cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j< m; j++){
                if(!vis[i][j] && grid[i][j] == 1) cnt++;
            }
        }

        return cnt;

    }
};