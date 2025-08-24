//Tabulation

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount+1,0));
        for(int i = 0; i<= amount; i++){
            if(i % coins[0] == 0) dp[0][i] = i / coins[0];
            else dp[0][i] = 1e9;
        }

        for(int i = 1; i< n; i++){
            for(int target = 0; target <= amount; target++){
                int pick = 1e9;
                if(coins[i] <= target) pick = 1 + dp[i][target - coins[i]];
                int notPick = 0 + dp[i-1][target];

                dp[i][target] = min(pick, notPick);
            }
        }

        int ans = dp[n-1][amount];
        if(ans == 1e9) return -1;
        return ans;
    }
};