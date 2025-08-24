class Solution {
public:
    void DFS(vector<vector<int>>& image, int sr, int sc, int color, int startColor, vector<vector<int>> &vis, vector<vector<int>> &ans){

        ans[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,-1,1};

        for(int i = 0 ; i< 4; i++){
            int nrow = sr + dr[i];
            int ncol = sc + dc[i];
            if(nrow >= 0 && ncol >=0 && nrow < n && ncol < m && 
            image[nrow][ncol] == startColor && ans[nrow][ncol] != color){
                DFS(image, nrow, ncol, color, startColor, vis, ans);
            }
            
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;

        vector<vector<int>> vis = image;

        ans[sr][sc] = color;
        int startColor = image[sr][sc];
        DFS(image, sr, sc, color, startColor, vis, ans);
        
        return ans;
    }

};