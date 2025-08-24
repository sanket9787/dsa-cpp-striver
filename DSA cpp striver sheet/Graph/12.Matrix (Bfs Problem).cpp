#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();
       queue<pair<pair<int,int>, int>> q; 
       vector<vector<int>> vis(n,vector<int>(m,0));
       vector<vector<int>> ans(n,vector<int>(m,0));
       
       for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            if(mat[i][j] == 0) {
                q.push({{i,j},0});
                vis[i][j] = 1;
            } 
        }
       }

       int dr[4] = {1,-1,0,0};
       int dc[4] = {0,0,-1,1};
       //we will use bfs starting from all 0th positions which are inserted in queue above
       //In the first wave we will mark all the ones near the zeros(which are at a distance of 1 from up down left right) with distance as 1, and push the index of the 1 with distance 1.
       //now when we come to this node of 1 above next time in queue, that time we will go in all 4 directions and if another 1 is not visited then we will mark it visited push it into queue with
       //distance as 2. likewise next waves will go.
       while(!q.empty()){

            int dis = q.front().second;
            int i = q.front().first.first;
            int j = q.front().first.second;
            q.pop();
            //once we get the element mark the ans matrix with the dis
            ans[i][j] = dis;

            for(int k=0 ; k<4; k++){
                int nrow = i + dr[k];
                int ncol = j + dc[k];
                if(nrow < n && nrow >=0 && ncol <m && ncol >= 0 &&
                !vis[nrow][ncol] && mat[nrow][ncol] == 1){
                    //this vis need to be in this above if condition if we do it outside the above for loop
                    //as the node is not visited same node could be inserted in the queue again 
                    //as the node is nearer to other 0 elements as well.
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, dis+1}); 
                }
            }
       }

       return ans;

    }
};


//Without vis vector
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();
       queue<pair<pair<int,int>, int>> q; 
       //vector<vector<int>> vis(n,vector<int>(m,0));
       vector<vector<int>> ans(n,vector<int>(m,0));
       
       for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            if(mat[i][j] == 0) {
                q.push({{i,j},0});
                //vis[i][j] = 1;
               // ans[i][j] = 1;
            } 
        }
       }

       int dr[4] = {1,-1,0,0};
       int dc[4] = {0,0,-1,1};
       //we will use bfs starting from all 0th positions which are inserted in queue above
       //In the first wave we will mark all the ones near the zeros(which are at a distance of 1 from up down left right) with distance as 1, and push the index of the 1 with distance 1.
       //now when we come to this node of 1 above next time in queue, that time we will go in all 4 directions and if another 1 is not visited then we will mark it visited push it into queue with
       //distance as 2. likewise next waves will go.
       while(!q.empty()){

            int dis = q.front().second;
            int i = q.front().first.first;
            int j = q.front().first.second;
            q.pop();
            //once we get the element mark the ans matrix with the dis
            //ans[i][j] = dis;

            for(int k=0 ; k<4; k++){
                int nrow = i + dr[k];
                int ncol = j + dc[k];
                if(nrow < n && nrow >=0 && ncol <m && ncol >= 0 &&
                !ans[nrow][ncol] && mat[nrow][ncol] == 1){
                    //this vis need to be in this above if condition if we do it outside the above for loop
                    //as the node is not visited same node could be inserted in the queue again 
                    //as the node is nearer to other 0 elements as well.
                    ans[nrow][ncol] = dis+1;
                    q.push({{nrow, ncol}, dis+1}); 
                }
            }
       }

       return ans;

    }
};

// [[0,1,0]
// [0,1,0]
// [0,1,0]
// [0,1,0]
// [0,1,0]]