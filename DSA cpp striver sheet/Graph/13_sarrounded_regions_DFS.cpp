class Solution {
public:
    void DFS(int i, int j, vector<vector<char>>& board, vector<vector<int>> &vis){
        int n = board.size();
        int m = board[0].size();
        vis[i][j] = 1;
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,-1,1};

        for(int k = 0 ; k< 4; k++){
            int nrow = i + dr[k];
            int ncol = j + dc[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
              !vis[nrow][ncol] && board[nrow][ncol] ==  'O' ){
                   DFS(nrow, ncol, board, vis);
              }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i = 0; i<n ;i++){
            for(int j = 0; j<m ; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    if(board[i][j] == 'O')  DFS(i, j, board, vis);
                }
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j< m; j++){
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X';
                }
                //cout << vis[i][j] << " ";
            }
            //cout << endl;
        }
    }
};