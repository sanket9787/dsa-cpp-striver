class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold){

        vector<vector<int>> dist(n, vector<int> (n,1e8));
        //remember to run this loop until edges.size not until n
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v=edges[i][1], wt = edges[i][2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int k = 0; k<n; k++){
            //cout << "k =" << k << endl;
            for(int i =0; i< n; i++){
                //assign distance to itself is zero
                dist[i][i] = 0;
                for(int j = 0; j<n; j++){
                    if(dist[i][k] < 1e8 && dist[k][j] < 1e8){
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                    //cout << dist[i][j] << " "; 
                }
                //cout << endl;
            }
            //cout << endl;
        }
        
        vector<int> cnt(n,0);
        for(int i =0; i< n; i++){
            for(int j = 0; j<n; j++){
                //cout << dist[i][j] << " ";
                //as dist to itself will be 0 hence exclude that
                if(dist[i][j] <= distanceThreshold && i != j){
                    cnt[i]++;
                }
            }
            //cout << endl;
        }

        //cout << endl;
        int min = INT_MAX;
        int ans;
        for(int i =0; i<n; i++){
            //cout << cnt[i] << " ";
            if(min >= cnt[i]){
                min = cnt[i];
                ans = i;
            } 
        }        
    
        return ans;
    }
};