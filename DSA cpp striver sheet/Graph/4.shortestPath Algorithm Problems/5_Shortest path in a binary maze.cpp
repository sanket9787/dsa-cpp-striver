class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1) return -1;
        if(n==1 && m ==1) return 1;

        //for all 8 directions
        int dr[8] = {0,0,-1,1,-1,-1,1,1};
        int dc[8] = {-1,1,0,0,-1,1,-1,1};
        
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dis(n, vector<int>(m,1e9));

        q.push({1,{0,0}});
        int dist = 1;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int i = front.second.first;
            int j = front.second.second;
            dist = front.first;
            
            for(int k =0; k<8; k++){
                int nrow = i + dr[k];
                int ncol = j + dc[k];
                if(nrow >=0 && ncol >= 0 && nrow < n && ncol < m &&
                grid[nrow][ncol] == 0){
                    //If we reach the ending point just return current dist + 1.
                    // we are returning because there is only difference of 1 in each block 
                    //and we are going to reach this via the fastest way through queue
                    //so another one who took longer time will obviously have larger distance to this block as the distance difference is same.
                    if(nrow == n-1 && ncol == m-1) return dist+1;
                    //If 1+dist is lesser than the previous distance until this node then only insert the node into queue, and update the dis matrix.
                    if(1+dist < dis[nrow][ncol]){
                        dis[nrow][ncol] = dist;
                        q.push({dist+1, {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }
};