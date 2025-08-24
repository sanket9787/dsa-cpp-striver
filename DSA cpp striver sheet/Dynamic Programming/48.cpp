//memoisatoin and recursion
int getAns(int i, int j, vector<int> &arr, vector<vector<int>>&dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        int multiple = 0;
        for(int k = i; k<j; k++){
                      // get the total number of multiplication when both partition are multiplied.
                      //from i to k and k+1 to j
            multiple = arr[i-1]*arr[k]*arr[j] + 
                       //get the total multiplication for first partition when all matrices in 
                       //first partition are mutlitplied together
                       //Here k will go as j as j is the last matrix of first partition.
                       getAns(i, k, arr, dp) +
                       //get total multiplication for second partition when all matrices in second
                       //are multiplied together.
                       //Here i will go as k+1. as i will be the start for the second partition
                        getAns(k+1, j, arr, dp);
                        
            if(mini > multiple) mini = multiple;
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int i = 1;
        int j = arr.size() - 1;
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return getAns(i, j, arr, dp);
    }

//Tabulation
