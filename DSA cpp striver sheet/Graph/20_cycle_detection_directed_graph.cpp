class Solution {
  public:
    bool DFS(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj){
        
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(DFS(it, vis, pathVis, adj)) return true;
            } 
            else if(pathVis[it]) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    
    bool isCyclic(int v, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(v);
        
        vector<int> vis(v,0);
        vector<int> pathVis(v,0);
        
        for(int i = 0; i<edges.size(); i++){
            int first = edges[i][0], second = edges[i][1];
            //push only second into first as it is a directed graph from first to second
            adj[first].push_back(second);
        }
        
        //start the check of cycle from each node 
        for(int i = 0; i < v; i++){
            if(!vis[i]) {
                if(DFS(i, vis, pathVis, adj) == true) return true;
            }
        }
        
        return false;
        
    }
};