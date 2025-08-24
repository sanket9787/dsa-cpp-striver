class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int vis[m][n];
        queue<vector<int>> q;

        //To keep the count of fresh oranges so later on to check if all of them are converted or not
        int cntfresh = 0;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0; j<n; j++){
                //Push the rotten oranges into the queue and mark the visited array as 2 (orange is rotten)
                if(grid[i][j] == 2){
                    //push all the already rotten oranges into queue with time variable as zero.
                    q.push({i,j,0});
                    vis[i][j] = 2;
                }else if(grid[i][j] == 1){
                    vis[i][j] = 1;
                    cntfresh++;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }
        //keeping the count of time
        int time = 0;
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,1,-1};

        int convertedRottenCnt = 0;
        
        //using bfs
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int i = node[0];
            int j = node[1];
            int k = node[2];
            time = max(time, k);

            for(int cnt = 0; cnt<4; cnt++){
                int row = i + dr[cnt];
                int col = j + dc[cnt];

                if(row < m && row >=0 && col < n && col >= 0 && vis[row][col] != 2 && 
                grid[row][col] == 1){
                    //if the orange its not visited and its not rotten then push it into queue for the next iterations like to rotten its sarrounding 4 oranges (bfs). then mark its position in visited as 2 means rotten.
                    //row, col is the position of orange and k+1 is the time after which is rottens.
                    q.push({row,col,k+1});
                    vis[row][col] = 2;
                    //converting fresh into rotten so increase the count of those of are converted to rotten just to check in the end if all are converted 
                    convertedRottenCnt++;
                }
            }
        }

        if(convertedRottenCnt != cntfresh) return -1;

        return time;
    }
};