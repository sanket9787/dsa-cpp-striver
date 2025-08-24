class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        if(n==1 && m == 1) return 0;
        vector<vector<int>> dis(n, vector<int>(m,1e9));
        
       priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;


        int dr[4] = {0,0,-1,1};
        int dc[4] = {-1,1,0,0};

        q.push({0, {0,0}});

        int maxRouteEffort = 0;
        //dis[0][0] = heights[0][0];
        while(!q.empty()){
            auto top = q.top();
            q.pop();
            int i = top.second.first;
            int j = top.second.second;
            maxRouteEffort = top.first;

            for(int k = 0; k<4; k++){
                int nrow = i + dr[k];
                int ncol = j + dc[k];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m ){
                    int heightDiff = abs(heights[i][j] - heights[nrow][ncol]);
                    int maxDiff = max(maxRouteEffort, heightDiff);
                    if(maxDiff < dis[nrow][ncol]){
                        dis[nrow][ncol] = maxDiff;
                        q.push({maxDiff,{nrow, ncol}});
                    } 
                }
            }
        }

        return dis[n-1][m-1];
    }
};