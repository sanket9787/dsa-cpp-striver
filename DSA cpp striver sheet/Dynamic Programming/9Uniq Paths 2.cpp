//memoisation and tabulation:
class Solution {
public:
    int getAns(vector<vector<int>>& nums,int m,int n, vector<vector<int>>& dp){
        if(m<0 || n < 0) return 0;
        if(nums[m][n] == 1) return 0;
        if(m == 0 && n == 0) return 1;

        if(dp[m][n] != -1) return dp[m][n];

        int up = getAns(nums,m-1,n,dp);
        int left = getAns(nums,m, n-1,dp);

        return dp[m][n] = up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
       
        int m = nums.size();
        int n = nums[0].size();
        // this edgecase handling not nesessary below algorithm handles this
        if(m == 1){
            if(nums[0][0] == 1) return 0;
        } 
        vector<vector<int>>dp(m, vector<int>(n,-1));
        //int ans = getAns(nums,m-1,n-1,dp);
        
        //cannot declare dp[0][0] = 1 outside for loop because we are using for loop from
        // i,j = 0; hence i-1 and j-1 inside for loop will go outbound or wont execute and 
        // dp[0][0] = up + left = 0   will become 0.
       // dp[0][0] = 1;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i==0 && j==0 && nums[i][j] == 0) dp[i][j] = 1;
                else if(nums[i][j] == 1) dp[i][j] = 0;
                else{
                    int up =0, left = 0;
                    if(i-1>=0) up = dp[i-1][j];
                    if(j-1>=0) left = dp[i][j-1];

                    dp[i][j] = up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};


//Space Optimisation

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
       
        int m = nums.size();
        int n = nums[0].size();
        
        if(nums[0][0] == 1) return 0;
    
        vector<int> prev(n,0);
        vector<int> curr(n,0);


        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                
                //check if first element is allowed if yess curr[0] = 1
                if(i==0 && j==0 && nums[i][j] == 0 ) curr[j] = 1;
                //else check if current element is allowed if not assing curr[j] = 0
                else if(nums[i][j] == 1) curr[j] = 0;
                else{

                    int up = 0, left = 0;
                    //for up we have to check for previous row that is i - 1 which is our prev dp array. for that the element index will be prev[j].   (i - 1 = prev)
                    up = prev[j];
                    //for left we have to check the previous element of curr dp array 
                    if(j-1>=0) left = curr[j-1];

                    //update the current jth index value into the curr dp array
                    curr[j] = up+left;
                }
            }
            prev = curr;
        }

        return prev[n-1];
    }
};



//Graph approach using dijkshra:
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //vector<vector<int>> dp(m, vector<int> (n,0));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

        vector<vector<int>> dis(m, vector<int>(n,1e8));

        dis[0][0] = grid[0][0];
        q.push({grid[0][0], {0,0}});

        int dr[2] = {1,0};
        int dc[2] = {0,1};

        while(!q.empty()){
            int currDis = q.top().first;
            int i = q.top().second.first;
            int j = q.top().second.second;
           
            q.pop();
            
            for(int k = 0; k< 2; k++){
                int nrow = i + dr[k];
                int ncol = j + dc[k];

                if(nrow < m && ncol < n ){
                    
                    if(currDis + grid[nrow][ncol] < dis[nrow][ncol]){
                        dis[nrow][ncol] = grid[nrow][ncol] + currDis;
                        q.push({dis[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }

        return dis[m-1][n-1];

    }
};