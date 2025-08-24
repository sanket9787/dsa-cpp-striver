class Solution {
  public:
    bool bfs(int start, vector<vector<int>> &list, vector<int> &vis){
        
        queue<pair<int,int>> q;
        //push start node and its previous node which is -1;
        q.push({start,-1});
        
        while(!q.empty()){
            auto front = q.front().first;
            auto prev = q.front().second;
            
            vis[front] = 1;
            q.pop();
            
            for(auto it : list[front]){
                //if the node is visited and its not equal to previous one 
                //it means cycle is detected.
                if(vis[it] && it != prev){
                    return true;
                }
                //if node is not visited then push it into queue with current front 
                //as the previous node of it node
                if(!vis[it] ){
                    q.push({it,front});
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        //Bfs approach
        int n = edges.size();
        
        vector<int> vis(V,0);
        vector<vector<int>> list(V);
        
        for(int i = 0; i < n; i++){
            int first = edges[i][0];
            int second = edges[i][1];
            list[first].push_back(second);
            list[second].push_back(first);
        }
        
        //check for all components
        for(int i = 0; i< V; i++){
            //i is the start node for each component. check for the cycle starting 
            //from i only if its is not visited.
            if(!vis[i]){
                //this will return if the component starting from node i has a cycle or not
                if(bfs(i, list, vis)) return true;
            }
        }
        
        return false;
        
    }
};


//Usign DFS
class Solution {
  public:
    bool DFS(int start,int prev, vector<vector<int>> &adj, vector<int> &vis){

        vis[start] = 1;
   
        for(auto it: adj[start]){
            if(vis[it] && it != prev) return true;
            if(!vis[it]) if(DFS(it, start, adj, vis)) return true;
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<int> vis(V, 0);
        
        for(auto it: edges){
            int first = it[0], sec = it[1];
            adj[first].push_back(sec);
            adj[sec].push_back(first); 
        }
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(DFS(i, -1, adj, vis)) return true;
            }
        }
        
        return false;
    }
};